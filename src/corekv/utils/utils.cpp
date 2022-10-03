//
// Created by qianyy on 10/3/22.
//

#include "utils.h"

namespace corekv {
    //计算data的checksum
    //折中方案：当前场景下没有必要计算checksum，使用一个固定的数即可
    //这里使用1233
    int64_t check_sum(int64_t data) {
        int64_t res = 1233L;
//        for (int i = 0; i < 64; ++i) {
//            res +=
//            data >>= 1;
//        }

        return res;
    }

    //计算128位string的hash
    hash<string> hash_fn;
}