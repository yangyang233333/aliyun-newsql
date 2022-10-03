//
// Created by qianyy on 10/3/22.
//
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


using std::string;
using std::cout;
using std::endl;

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
        //2亿条272+8B的数据，大约52.15 GB，所以开辟55 GB的空间
        if ((context.fileaddr = (char *) pmem_map_file(context.filepath.c_str(),
                                                       context.file_size,
                                                       PMEM_FILE_CREATE,
                                                       0666,
                                                       &context.mapped_len,
                                                       &context.is_pmem)) == nullptr) {
            cout << "文件创建失败！" << endl;
            exit(1);
        }

        //解析文件，获取下一条数据的写入位置




//        string HOST_INFO = host_info;
//
//        string AEP_DIR = aep_dir;
//        string DISK_DIR = disk_dir;
//        size_t PEER_HOST_INFO_NUM = peer_host_info_num;
//
//        cout << "HOST_INFO=" << HOST_INFO << ", AEP_DIR=" << AEP_DIR << ", DISK_DIR=" << DISK_DIR
//             << ", PEER_HOST_INFO_NUM="
//             << PEER_HOST_INFO_NUM << endl;
//        for (size_t i = 0; i < peer_host_info_num; ++i) {
//            cout << "第 [" << i << "] 次：" << peer_host_info[i] << endl;
//        }

        return nullptr;
    }

    void engine_deinit(void *ctx) {

    }

    /*
     * 写入数据的schema
     * +---------+---------------+------------+------------+--------------+
     * |  id(8B) | user_id(128B) | name(128B) | salary(8B) | checksum(8B) |
     * +---------+---------------+------------+------------+--------------+
     *
     * */
    void engine_write(void *ctx, const void *data, size_t len) {
        User user;
        memcpy(&user, data, len);

    }

    size_t engine_read(void *ctx, int32_t select_column,
                       int32_t where_column, const void *column_key, size_t column_key_len, void *res) {


        return 0;
    }
}
