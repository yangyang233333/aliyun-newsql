//
// Created by qianyangyang on 9/25/22.
//
#include <stdint.h>

#include <iostream>
#include <functional>
#include <string>
#include <stdint.h>

using namespace std;

struct User {
    int64_t id;
    char name[128];
};

int main() {
    //hash的用法
    std::hash <string> hash_fn;
    size_t n = hash_fn("1");
    cout << n << endl;
}

