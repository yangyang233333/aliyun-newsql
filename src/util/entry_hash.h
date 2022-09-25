//
// Created by qianyangyang on 9/25/22.
//

#include "../common.h"
#include <iostream>
#include <functional>
#include <string>
#ifndef CLION_HASH_H
#define CLION_HASH_H

namespace woaikv {
    extern std::hash<User> user_hash;

    int64_t hash_entry(User &user) {
        return user_hash(user);
    }

}

#endif //CLION_HASH_H
