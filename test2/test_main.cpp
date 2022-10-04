//
// Created by qianyangyang on 2022/10/2.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <atomic>
#include <thread>
#include <string.h>
//仅用于测试corekv
#include "corekv/common.h"
#include "corekv/api.h"

using namespace std;

// 测试hmap的内存占用
//void test_hmap() {
//    unordered_map<int64_t, uint32_t> hmap;
//    int a = system("free -m");
//
//    for (size_t i = 0; i < 2*10000 * 10000; ++i) {
//        hmap.insert(make_pair(i,i+2));
//    }
//
//    a = system("free -m");
//
//}

// 测试以下corekv
void test_corekv() {
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
        cout << "【测试语句】：select salary from . where id=xxx" << endl;
        for (auto &u: user_vec) {
            int64_t salary;
            corekv::engine_read(nullptr,
                                corekv::Salary,
                                corekv::Id,
                                &(u.id),
                                8,
                                &salary);
//        cout << "读取的salary=" << salary << ", 真实的salary=" << u.salary << endl;
            if (salary != u.salary) {
                cout << "【测试失败】：读取错误！salary字段不相等" << endl;
                exit(1);
            }
        }
        cout << "【测试成功】：select salary from . where id=xxx" << endl;
    }

};

int main() {

    test_corekv();

//    corekv::User user{};
//    user.id = 5;
//    string uid = "123";
//    memcpy(user.user_id, uid.c_str(), uid.size());
//    cout << "user.id=" << user.id << ", user.user_id=" << user.user_id << endl;


//    test_atomic();

//    multimap<int64_t, int32_t> mm;
//    mm.insert(make_pair(1, 1));
//    mm.insert(make_pair(1, 2));
//
//    auto range = mm.equal_range(1);
//    for (auto iter = range.first;
//         iter != range.second; ++iter) {
//        auto a = iter->first;
//        auto b = iter->second;
//    }



}

