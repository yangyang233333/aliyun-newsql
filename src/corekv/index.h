//
// Created by qianyangyang on 2022/10/2.
//

#ifndef WOAIKV_INDEX_H
#define WOAIKV_INDEX_H

#include <unordered_map>
#include <map>

using std::map;
using std::unordered_map;
using std::multimap;

namespace corekv {
    class Index {
    public:
        Index() = default;


    public:
        //下面三个分别是id、uid、salary在内存中的索引
        unordered_map<int64_t, uint32_t> id_map;
        unordered_map<int64_t, uint32_t> uid_map;
        multimap<int64_t, uint32_t> salary_map;
    };
}


#endif //WOAIKV_INDEX_H
