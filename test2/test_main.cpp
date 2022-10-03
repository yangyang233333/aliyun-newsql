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
//void test_hmap() {
//    unordered_map<int64_t, uint32_t> hmap;
//    system("free -m");
//
//    for(size_t ){
//
//    }
//
//
//    system("free -m");
//
//}

atomic<int32_t> ai;

void add() {
    for (int i = 0; i < 10 * 10000; ++i) {
        ++ai;
    }
}

void test_atomic() {
    ai = 0;
    vector<thread> thread_pool;
    for (int i = 0; i < 50; ++i) {
        thread_pool.emplace_back(add);
    }
    for (auto &t: thread_pool) {
        t.join();
    }
    cout << "ai=" << ai << endl;
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


//    cout << "Hello World!" << endl;
//    const char *aep_dir = "/mnt/aep/";
//    cout << aep_dir << endl;
//
//    int64_t file_size = 55L * 1024 * 1024 * 1024;//55GB
//    cout << file_size << endl;
}

