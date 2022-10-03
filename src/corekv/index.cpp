//
// Created by qianyangyang on 2022/10/2.
//
#include "global_var.h"
#include "context.h"
#include "index.h"
#include "utils/utils.h"
#include <string.h>

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
        if (){

        }

    }

}