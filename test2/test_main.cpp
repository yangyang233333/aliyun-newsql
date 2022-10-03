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

int main() {
//    test_atomic();

    atomic<int64_t> aa{0};
    auto a = aa++;
    cout << "a=" << a << " aa=" << aa << endl;

//    cout << "Hello World!" << endl;
//    const char *aep_dir = "/mnt/aep/";
//    cout << aep_dir << endl;
//
//    int64_t file_size = 55L * 1024 * 1024 * 1024;//55GB
//    cout << file_size << endl;
}

