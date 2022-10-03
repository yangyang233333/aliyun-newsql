//
// Created by qianyangyang on 2022/10/2.
//

#ifndef WOAIKV_INDEX_H
#define WOAIKV_INDEX_H

#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::map;
using std::unordered_map;
using std::multimap;

namespace corekv {
    class Index {
    public:
        Index() = default;

        //扫描全局文件，建立索引
        void build_index();

        //pk指id，主键
        int32_t pk_insert(int64_t id, int32_t offset);

        int32_t pk_get(int64_t id) const;

        //uk指uid，unique键
        int32_t uk_insert(string &user_id, int32_t offset);

        int32_t uk_get(string &user_id) const;


        //sk指salary，有重复
        int32_t sk_insert(int64_t salsry, int32_t offset);

        int32_t sk_get(int64_t salary, vector <int32_t> &offset_vec);

    private:
        //下面三个分别是id、uid、salary在内存中的索引
        unordered_map <int64_t, int32_t> id_map;
        unordered_map <int64_t, int32_t> uid_map;
        multimap <int64_t, int32_t> salary_map;

        //主要防止uid_map的冲突。一旦发现，就需要把该pair提取到uid_map2中
        //然后把改建早uid_map中对应的offset改为-10（表示存在冲突）
        unordered_map <string, int32_t> uid_map2;
    };
}


#endif //WOAIKV_INDEX_H
