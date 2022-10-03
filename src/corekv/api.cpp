//
// Created by qianyy on 10/3/22.
//
#include "utils/utils.h"
#include "common.h"
#include "api.h"
#include "global_var.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <libpmem.h>
#include <libpmem.h>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;
using std::hash;

namespace corekv {
    /*
* Initialization interface, which is called when the engine starts.
* You need to create or recover db from pmem-file.
* host_info: Local machine information including ip and port. This value is nullptr in the preliminary round.
* peer_host_info: Information about other machines in the distributed cluster. This value is nullptr in the preliminary round.
* peer_host_info_num: The num of other machines in the distributed cluster.  This value is 0 in the preliminary round.
* aep_dir: AEP file directory, eg : "/mnt/aep/"
* disk_dir: Disk file directory, eg : "/mnt/disk/"
*/
    void *engine_init(const char *host_info, const char *const *peer_host_info, size_t peer_host_info_num,
                      const char *aep_dir, const char *disk_dir) {
        cout << "调用了一次【engine_init】." << endl;

        //Context结构体初始化
        string AEP_DIR = aep_dir; //"/mnt/aep/"
        string DISK_DIR = disk_dir; //"/mnt/disk/"
        context.filepath = AEP_DIR + "pmem_file";
        context.file_size = 55L * 1024 * 1024 * 1024;//55GB
        context.offset = 0; //下一条数据应该写入的位置

        // 创建文件
        // 2亿条272+8B的数据，大约52.15 GB，所以开辟55 GB的空间
        if ((context.fileaddr = (char *) pmem_map_file(context.filepath.c_str(),
                                                       context.file_size,
                                                       PMEM_FILE_CREATE,
                                                       0666,
                                                       &context.mapped_len,
                                                       &context.is_pmem)) == nullptr) {
            cout << "文件创建失败！" << endl;
            exit(1);
        }

        //解析文件，获取下一条数据的写入位置(即offset)
        context.parse_file_to_get_offset();

        //todo:扫描文件，建立索引
        

        return nullptr;
    }

    void engine_deinit(void *ctx) {
        cout << "调用了一次【engine_deinit】." << endl;

    }

    /*
     * 写入数据的schema
     * +---------+---------------+------------+------------+--------------+
     * |  id(8B) | user_id(128B) | name(128B) | salary(8B) | checksum(8B) |
     * +---------+---------------+------------+------------+--------------+
     *
     * */
    void engine_write(void *ctx, const void *data, size_t len) {
        cout << "调用了一次【engine_write】." << endl;

        //写数据的步骤
        // 1. 先写磁盘
        User *user = (User *) data;
        int32_t offset = context.get_offset();
        int64_t checksum = check_sum(user->id);
        pmem_memcpy_persist(context.fileaddr + offset * 280, user, 272);
        pmem_memcpy_persist(context.fileaddr + offset * 280 + 272, &checksum, 8);

        // 2. 后更新索引
        index.pk_insert(user->id, offset);
        string _user_id(user->user_id, 128);
        index.uk_insert(_user_id, offset);
        index.sk_insert(user->salary, offset);
    }

    /*
     * 模拟SELECT select_column FROM table_name WHERE where_column = column_key
     * 注意：WHERE中不存在name=xxx，但是SELECT中存在name=xxx
     * 根据题意，有以下三种查询语句：
     * 1. SELECT select_column FROM table_name WHERE id = xxx
     * 2. SELECT select_column FROM table_name WHERE user_id = xxx
     * 3. SELECT select_column FROM table_name WHERE salary = xxx
     * 其中select_column可能为id, user_id, name, salary四个之一。
     *
     * 详细分析这三种情况：
     * 第一种情况：查询字段为id，这种情况返回值只有0个或1个。
     * 那么建立的索引结构可以为：unordered_map<id, gid>，通过gid去找到需要返回的字段（id, user_id, name, salary）
     *
     * 第二种情况：查询字段为user_id，这种情况返回值只有0个或1个。
     * 那么建立的索引结构可以为：unordered_map<user_id, gid>，通过gid去找到需要返回的字段（id, user_id, name, salary）
     *
     * 第三种情况：查询字段为salary，这种情况较为复杂，返回值数量n属于[0, 2000]
     * 其索引结构可以为multimap<salary, gid>
     *
     * */
    size_t engine_read(void *ctx,
                       int32_t select_column,
                       int32_t where_column,
                       const void *column_key,
                       size_t column_key_len,
                       void *res) {
        cout << "调用了一次【engine_read】." << endl;

        size_t res_num = 0;
        vector<int32_t> offset_vec;
        switch (where_column) {
            case Id: {
                auto offset = index.pk_get(*(int64_t *) column_key);
                if (offset == -5) {
                    res_num = 0;
                } else {
                    offset_vec.push_back(offset);
                    res_num = 1;
                }
                break;
            }
            case Userid: {
                string user_id_str((char *) column_key, 128);
                auto offset = index.uk_get(user_id_str);
                if (offset == -5) {
                    res_num = 0;
                } else {
                    offset_vec.push_back(offset);
                    res_num = 1;
                }
                break;
            }
            case Salary: {
                //todo:此处可能有问题
                auto offset = index.sk_get(*(int64_t *) column_key, offset_vec);
                if (offset == -5) {
                    res_num = 0;
                } else {
                    res_num = offset_vec.size();
                }
                break;
            }
            default: {
                cout << "where_column=" << where_column << "不存在。" << endl;
                return 0;
            }
        }

        //如果数据不存在直接返回
        if (res_num == 0) {
            return 0;
        }
        //此时数据存在
        switch (select_column) {
            case Id: {
                for (auto offset: offset_vec) {
                    memcpy(res, context.fileaddr + 280L * offset, 8);
                    res = (char *) res + 8;
                }
                break;
            }
            case Userid: {
                for (auto offset: offset_vec) {
                    memcpy(res, context.fileaddr + 280L * offset + 8, 128);
                    res = (char *) res + 128;
                }
                break;
            }
            case Name: {
                for (auto offset: offset_vec) {
                    memcpy(res, context.fileaddr + 280L * offset + 136, 128);
                    res = (char *) res + 128;
                }
                break;
            }
            case Salary: {
                for (auto offset: offset_vec) {
                    memcpy(res, context.fileaddr + 280L * offset + 264, 8);
                    res = (char *) res + 8;
                }
                break;
            }
            default: {
                cout << "select_column=" << select_column << "不存在。" << endl;
                return 0;
            }
        }

        return res_num;
    }
}
