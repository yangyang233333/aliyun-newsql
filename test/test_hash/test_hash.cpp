//
// Created by qianyangyang on 9/25/22.
//
#include <cstdint>
#include <iostream>
#include <functional>
#include <string>

using namespace std;

struct User {
    int64_t id;
    char name[128];
};

int main() {
    //hash的用法
    std::hash<string> hash_fn;
    size_t n = hash_fn("1");
    cout << n << endl;
    cout << hash_fn("1") << endl;
    auto a = hash<string>();
    cout << hash<string>()("1") << endl;
    cout << UINT32_MAX << endl;


}

