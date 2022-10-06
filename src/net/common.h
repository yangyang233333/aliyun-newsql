//
// Created by qianyy on 10/6/22.
//

#ifndef INTERFACE_COMMON_H
#define INTERFACE_COMMON_H

#include <string>
#include <cstdint>


namespace corekv_net {

    //请求信息
    //也就是模拟SELECT select_column FROM . WHERE where_column=column_key

    struct Request {
        int32_t select_column;
        int32_t where_column;
        char column_key[128];
        size_t column_key_len;
    };

    //根据返回值的数量和类型进行区分
    //指where_column=id/user_id，select_column=*
    struct Reply_1 {
        Request req;//请求信息
        int32_t cnt;//查询到的数量0~1
        char result[128];//查询到的结果
    };

    //指where_column=salary并且select_column为id
    struct Reply_2000_8 {
        Request req;//请求信息
        int32_t cnt;//查询到的数量0~2000
        char result[8 * 2000];//查询到的结果
    };

    //指where_column=salary并且select_column为user_id/name
    struct Reply_2000_128 {
        Request req;//请求信息
        int32_t cnt;//查询到的数量0~2000
        char result[128 * 2000];//查询到的结果
    };
}

#endif //INTERFACE_COMMON_H
