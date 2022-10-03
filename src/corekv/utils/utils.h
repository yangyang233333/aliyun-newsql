//
// Created by qianyy on 10/3/22.
//

#ifndef INTERFACE_UTILS_H
#define INTERFACE_UTILS_H
#include <stdint.h>
#include <string>
using std::string;
using std::hash;
namespace corekv{
    //计算data的checksum
    extern int64_t check_sum(int64_t data);

    //计算string的hash
    extern hash<string> hash_fn;
}

#endif //INTERFACE_UTILS_H
