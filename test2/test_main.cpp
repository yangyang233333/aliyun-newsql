//
// Created by qianyangyang on 2022/10/2.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <atomic>
#include <thread>
#include <set>
#include <unordered_set>
#include <cstring>
//仅用于测试corekv
#include "corekv/common.h"
#include "corekv/api.h"
using namespace std;

// 测试以下corekv
// 测试标准：先写后读
void test_corekv1() {
    corekv::engine_init(nullptr,
                        nullptr,
                        0,
                        "/mnt/aep/",
                        "/mnt/disk/");
    cout << "数据生成中..." << endl;
    vector<corekv::User> user_vec;
    for (auto i = 0; i < 10 * 10000; ++i) {
        corekv::User user{};
        user.id = i;
        user.salary = i % 5000;
        auto uid = "userid_" + to_string(i);
        auto name = "name_" + to_string(i);
        memcpy(user.user_id, uid.c_str(), uid.size());
        memcpy(user.name, name.c_str(), name.size());
        user_vec.push_back(user);
    }

    cout << "开始写入... ..." << endl;
    for (auto &u: user_vec) {
        corekv::engine_write(nullptr,
                             &u,
                             272);
    }
    cout << "开始读取测试... ..." << endl;

    if (true) {
        if (true) {
            cout << "【测试语句】：select id from . where id=xxx" << endl;
            for (auto &u: user_vec) {
                int64_t id;
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Id,
                                                 corekv::Id,
                                                 &(u.id),
                                                 8,
                                                 &id);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (id != u.id) {
                    cout << "【测试失败】：读取错误！id字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select id from . where id=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select user_id from . where id=xxx" << endl;
            for (auto &u: user_vec) {
                char user_id[128];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Userid,
                                                 corekv::Id,
                                                 &(u.id),
                                                 8,
                                                 &user_id);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (memcmp(user_id, u.user_id, 128) != 0) {
                    cout << "【测试失败】：读取错误！user_id字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select user_id from . where id=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select name from . where id=xxx" << endl;
            for (auto &u: user_vec) {
                char name[128];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Name,
                                                 corekv::Id,
                                                 &(u.id),
                                                 8,
                                                 &name);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (memcmp(name, u.name, 128) != 0) {
                    cout << "【测试失败】：读取错误！name字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select name from . where id=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select salary from . where id=xxx" << endl;
            for (auto &u: user_vec) {
                int64_t salary;
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Salary,
                                                 corekv::Id,
                                                 &(u.id),
                                                 8,
                                                 &salary);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (salary != u.salary) {
                    cout << "【测试失败】：读取错误！salary字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select salary from . where id=xxx" << endl;
        }
    }
    cout << "【全部测试成功】：select * from . where id=xxx" << endl;

    if (true) {
        if (true) {
            cout << "【测试语句】：select id from . where user_id=xxx" << endl;
            for (auto &u: user_vec) {
                int64_t id;
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Id,
                                                 corekv::Userid,
                                                 &(u.user_id),
                                                 128,
                                                 &id);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (id != u.id) {
                    cout << "【测试失败】：读取错误！id字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select id from . where user_id=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select user_id from . where user_id=xxx" << endl;
            for (auto &u: user_vec) {
                char user_id[128];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Userid,
                                                 corekv::Userid,
                                                 &(u.user_id),
                                                 128,
                                                 &user_id);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (memcmp(user_id, u.user_id, 128) != 0) {
                    cout << "【测试失败】：读取错误！user_id字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select user_id from . where user_id=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select name from . where user_id=xxx" << endl;
            for (auto &u: user_vec) {
                char name[128];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Name,
                                                 corekv::Userid,
                                                 &(u.user_id),
                                                 128,
                                                 &name);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (memcmp(name, u.name, 128) != 0) {
                    cout << "【测试失败】：读取错误！name字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select name from . where user_id=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select salary from . where user_id=xxx" << endl;
            for (auto &u: user_vec) {
                int64_t salary;
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Salary,
                                                 corekv::Userid,
                                                 &(u.user_id),
                                                 128,
                                                 &salary);
                if (!(cnt == 0 || cnt == 1)) {
                    cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
                    exit(1);
                }
                if (salary != u.salary) {
                    cout << "【测试失败】：读取错误！salary字段不相等" << endl;
                    exit(1);
                }
            }
            cout << "【测试成功】：select salary from . where user_id=xxx" << endl;
        }
    }
    cout << "【全部测试成功】：select * from . where user_id=xxx" << endl;

    //根据salary字段算出salary->User的索引
    if (true) {
        multimap<int64_t, corekv::User> mmap;
        for (auto &u: user_vec) {
            mmap.insert(make_pair(u.salary, u));
        }
        if (true) {
            cout << "【测试语句】：select id from . where salary=xxx" << endl;
            for (auto &u: user_vec) {
                char ids[8 * 2000];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Id,
                                                 corekv::Salary,
                                                 &u.salary,
                                                 8,
                                                 ids);
                auto f = mmap.equal_range(u.salary);
                vector<int64_t> id1, id2;
                for (auto iter = f.first; iter != f.second; ++iter) {
                    id1.push_back(iter->second.id);
                }
                for (size_t i = 0; i < cnt; ++i) {
                    int64_t t;
                    memcpy(&t, ids + i * 8, 8);
                    id2.push_back(t);
                }
                if (id1.size() != id2.size()) {
                    cout << id1.size() << " " << id2.size() << " " << cnt << endl;
                    cout << "【测试失败】：读取错误！id长度不相等" << endl;
                    exit(1);
                }
                for (size_t i = 0; i < id1.size(); ++i) {
                    if (id1[i] != id2[i]) {
                        cout << "【测试失败】：读取错误！id1[i] != id2[i]" << endl;
                        exit(1);
                    }
                }
            }
            cout << "【测试成功】：select id from . where salary=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select user_id from . where salary=xxx" << endl;
            for (auto &u: user_vec) {
                char userids[128 * 2000];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Userid,
                                                 corekv::Salary,
                                                 &u.salary,
                                                 8,
                                                 userids);
                auto f = mmap.equal_range(u.salary);
                vector<string> userids1, userids2;
                for (auto iter = f.first; iter != f.second; ++iter) {
                    userids1.emplace_back(iter->second.user_id);
                }
                for (size_t i = 0; i < cnt; ++i) {
                    char t[128];
                    memcpy(t, userids + i * 128, 128);
                    userids2.emplace_back(t);
                }
                if (userids1.size() != userids2.size()) {
                    cout << userids1.size() << " " << userids2.size() << " " << cnt << endl;
                    cout << "【测试失败】：读取错误！userid长度不相等" << endl;
                    exit(1);
                }
                for (size_t i = 0; i < userids1.size(); ++i) {
                    if (userids1[i] != userids2[i]) {
                        cout << "【测试失败】：读取错误！userids1[i] != userids2[i]" << endl;
                        exit(1);
                    }
                }
            }
            cout << "【测试成功】：select user_id from . where salary=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select name from . where salary=xxx" << endl;
            for (auto &u: user_vec) {
                char name[128 * 2000];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Name,
                                                 corekv::Salary,
                                                 &u.salary,
                                                 8,
                                                 name);
                auto f = mmap.equal_range(u.salary);
                vector<string> names1, names2;
                for (auto iter = f.first; iter != f.second; ++iter) {
                    names1.emplace_back(iter->second.name);
                }
                for (size_t i = 0; i < cnt; ++i) {
                    char t[128];
                    memcpy(t, name + i * 128, 128);
                    names2.emplace_back(t);
                }
                if (names1.size() != names2.size()) {
                    cout << names1.size() << " " << names2.size() << " " << cnt << endl;
                    cout << "【测试失败】：读取错误！name长度不相等" << endl;
                    exit(1);
                }
                for (size_t i = 0; i < names1.size(); ++i) {
                    if (names1[i] != names2[i]) {
                        cout << "names1[i], names2[i]=" << names1[i] << "," << names2[i] << endl;
                        cout << "【测试失败】：读取错误！names1[i] != names2[i]" << endl;
                        exit(1);
                    }
                }
            }
            cout << "【测试成功】：select name from . where salary=xxx" << endl;
        }

        if (true) {
            cout << "【测试语句】：select salary from . where salary=xxx" << endl;
            for (auto &u: user_vec) {
                char ids[8 * 2000];
                size_t cnt = corekv::engine_read(nullptr,
                                                 corekv::Salary,
                                                 corekv::Salary,
                                                 &u.salary,
                                                 8,
                                                 ids);
                auto f = mmap.equal_range(u.salary);
                vector<int64_t> salary1, salary2;
                for (auto iter = f.first; iter != f.second; ++iter) {
                    salary1.push_back(iter->second.salary);
                }
                for (size_t i = 0; i < cnt; ++i) {
                    int64_t t;
                    memcpy(&t, ids + i * 8, 8);
                    salary2.push_back(t);
                }
                if (salary1.size() != salary2.size()) {
                    cout << salary1.size() << " " << salary2.size() << " " << cnt << endl;
                    cout << "【测试失败】：读取错误！salary长度不相等" << endl;
                    exit(1);
                }
                for (size_t i = 0; i < salary1.size(); ++i) {
                    if (salary1[i] != salary2[i]) {
                        cout << "【测试失败】：读取错误！id1[i] != id2[i]" << endl;
                        exit(1);
                    }
                }
            }
            cout << "【测试成功】：select salary from . where salary=xxx" << endl;
        }
    }
    cout << "【全部测试成功】：select * from . where salary=xxx" << endl;

    cout << "【全部测试成功】:select * from . where *=xxx." << endl;
};

// 测试以下corekv
// 测试标准：混合读写
void test_corekv2() {
    corekv::engine_init(nullptr,
                        nullptr,
                        0,
                        "/mnt/aep/",
                        "/mnt/disk/");
    cout << "数据生成中..." << endl;
    vector<corekv::User> user_vec;
    for (auto i = 0; i < 10 * 10000; ++i) {
        corekv::User user{};
        user.id = i;
        user.salary = i % 5000;
        auto uid = "userid_" + to_string(i);
        auto name = "name_" + to_string(i);
        memcpy(user.user_id, uid.c_str(), uid.size());
        memcpy(user.name, name.c_str(), name.size());
        user_vec.push_back(user);
    }

    //简单起见，混合读写只测试select salary from . where id=xxx.
    cout << "写第0~10000条... ..." << endl;
    for (auto i = 0; i < 10000; ++i) {
        corekv::engine_write(nullptr,
                             &user_vec[i],
                             272);
    }
    cout << "读取0~10000条... ..." << endl;
    for (auto i = 0; i < 10000; ++i) {
        auto u = user_vec[i];
        int64_t salary;
        size_t cnt = corekv::engine_read(nullptr,
                                         corekv::Salary,
                                         corekv::Id,
                                         &(u.id),
                                         8,
                                         &salary);
        if (!(cnt == 0 || cnt == 1)) {
            cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
            exit(1);
        }
        if (salary != u.salary) {
            cout << "【测试失败】：读取错误！salary字段不相等" << endl;
            exit(1);
        }
    }

    cout << "写第10000~20000条... ..." << endl;
    for (auto i = 10000; i < 20000; ++i) {
        corekv::engine_write(nullptr,
                             &user_vec[i],
                             272);
    }

    cout << "读取0~20000条... ..." << endl;
    for (auto i = 0; i < 20000; ++i) {
        auto u = user_vec[i];
        int64_t salary;
        size_t cnt = corekv::engine_read(nullptr,
                                         corekv::Salary,
                                         corekv::Id,
                                         &(u.id),
                                         8,
                                         &salary);
        if (!(cnt == 0 || cnt == 1)) {
            cout << "【测试失败】：读取错误！cnt必须为0/1" << endl;
            exit(1);
        }
        if (salary != u.salary) {
            cout << "【测试失败】：读取错误！salary字段不相等" << endl;
            exit(1);
        }
    }

    cout << "【混合读写测试成功】：select salary from . where id=xxx" << endl;
}

// 测试hmap的内存占用
void test_hmap() {
    unordered_map<int64_t, uint32_t> hmap;
    int a = system("free -m");

    for (size_t i = 0; i < 500 * 10000; ++i) {
        hmap.insert(make_pair(i, i + 2));
    }

    a = system("free -m");

}

int main() {
//    测试corekv
//    注意：这两个测试不可以同时运行，一次只能运行一个
//    因为写入的文件相同，1写入的数据会对2产生干扰
//    test_corekv1();
//    test_corekv2();

//    测试unordered_map内存占用
    test_hmap();


}

