//
// Created by qianyangyang on 9/24/22.
//
#include <stdint.h>

#ifndef CLION_COMMON_H
#define CLION_COMMON_H

namespace corekv {
    //定义Entry结构
    struct User {
        int64_t id;
        char user_id[128];
        char name[128];
        int64_t salary;
    };
}

#endif //CLION_COMMON_H