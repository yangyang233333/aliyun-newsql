//
// Created by qianyangyang on 2022/10/2.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <atomic>
#include <thread>

using namespace std;

// 测试hmap的内存占用
void test_hmap() {
    unordered_map<int64_t, uint32_t> hmap;
    int a = system("free -m");

    for (size_t i = 0; i < 2*10000 * 10000; ++i) {
        hmap.insert(make_pair(i,i+2));
    }

    a = system("free -m");

}

// 测试以下corekv
void test_corekv() {


};

int main() {
//    test_atomic();
    multimap<int64_t, int32_t> mm;
    mm.insert(make_pair(1, 1));
    mm.insert(make_pair(1, 2));

    auto range = mm.equal_range(1);
    for (auto iter = range.first;
         iter != range.second; ++iter) {
        auto a = iter->first;
        auto b = iter->second;
    }

    test_hmap();

}

