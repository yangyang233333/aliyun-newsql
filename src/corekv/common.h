//
// Created by qianyangyang on 9/24/22.
//

#ifndef CLION_COMMON_H
#define CLION_COMMON_H
#include <stdint.h>
//#include ""
namespace corekv {
    //定义Entry结构
    struct User {
        int64_t id;
        char user_id[128];
        char name[128];
        int64_t salary;
    };

    enum Column {
        Id = 0,
        Userid,
        Name,
        Salary
    };


}

#endif //CLION_COMMON_H
