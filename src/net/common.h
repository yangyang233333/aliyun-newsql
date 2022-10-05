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
        std::string column_key;
    };

    //回复信息
    struct Reply {
        Request req;
        int32_t cnt = 0;//查询到的数量
        std::string rep;
    };
}

#endif //INTERFACE_COMMON_H
