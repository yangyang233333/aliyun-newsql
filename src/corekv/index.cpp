//
// Created by qianyangyang on 2022/10/2.
//
#include "global_var.h"
#include "context.h"
#include "index.h"
#include "utils/utils.h"
#include <string.h>
#include "common.h"

namespace corekv {

    int32_t Index::pk_insert(int64_t id, int32_t offset) {
        this->id_map[id] = offset;
        return 0;
    }

    int32_t Index::pk_get(int64_t id) const {
        auto f = this->id_map.find(id);
        if (f == id_map.end()) {
            return -5; //表示id键未找到
        } else {
            return f->second;
        }
    }

    int32_t Index::uk_insert(string &user_id, int32_t offset) {
        int64_t hash_val = hash_fn(user_id);
        auto f1 = this->uid_map.find(hash_val);
        if (f1 == this->uid_map.end()) {
            //uid_map中不存在，则直接插入
            this->uid_map[hash_val] = offset;
        } else {
            //已经存在，需要插入到uid_map2中
            //1.判断数据是否等于-10
            if (f1->second == -10) {
                //说明数据已经从uid_map取出，并且放入到uid_map2中
                //此时只需要把新数据插入到uid_map2
                this->uid_map2[user_id] = offset;
            } else {
                //此时需要取出数据，放入到uid_map2中
                char old_user_id[128];
                int32_t old_offset = f1->second; //旧数据的offset
                memcpy(old_user_id, context.fileaddr + old_offset * 280 + 8, 128);
                string old_user_id2(old_user_id, 128);

                //新旧数据一起插入到uid_map2中
                this->uid_map2[old_user_id2] = old_offset;
                this->uid_map2[user_id] = offset;

                //标记uid_map中对应键的val为-10（表示冲突，并且数据已经取出，需要到uid_map2中查找）
                this->uid_map[hash_val] = -10;
            }
        }
        return 0;
    }

    int32_t Index::uk_get(string &user_id) const {
        int64_t hash_val = hash_fn(user_id);
        auto f = uid_map.find(hash_val);
        if (f == uid_map.end()) {
            return -5;//表示未找到
        } else {
            if (f->second == -10) {
                //此时存在，但是有冲突。需要进一步到uid_map2查找
                auto ff = uid_map2.find(user_id);
                return ff->second;
            } else {
                //此时存在，并且没有冲突，所以直接返回uid_map的数据即可
                return f->second;
            }
        }
    }

    int32_t Index::sk_insert(int64_t salsry, int32_t offset) {
        this->salary_map.insert(std::make_pair(salsry, offset));
        return 0;
    }

    int32_t Index::sk_get(int64_t salary, vector<int32_t> &offset_vec) {
        auto range = salary_map.equal_range(salary);
        for (auto iter = range.first;
             iter != range.second; ++iter) {
            offset_vec.push_back(iter->second);
        }
        if (offset_vec.empty()) {
            return -5; //表示没找到
        }
        return 0;
    }

    void Index::build_index() {
        for (int32_t i = 0; i < context.offset; ++i) {
            User user{};
            int64_t checksum;
            //todo:这里可以换掉memcpy，直接使用指针转换
            memcpy(&user, context.fileaddr + i * 280L, 272);
            memcpy(&checksum, context.fileaddr + i + 280L + 272, 8);
            if (check_sum(user.id) == checksum) {
                //更新索引
                pk_insert(user.id, i);
                string uid_str(user.user_id, 128);
                uk_insert(uid_str, i);
                sk_insert(user.salary, i);
            }
        }
    }

}