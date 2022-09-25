//
// Created by qianyangyang on 9/25/22.
//
#inclde <stdint.h>

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
    User user{};
    user.id = 45;
    std::hash <User> hash_fn;
    int64_t n = hash_fn(user);
    cout << n << endl;
//    std::string str = "Meet the new boss...";
//    std::hash <std::string> hash_fn;
//    int64_t str_hash = hash_fn(str);
//
//    std::cout << str_hash << '\n';
//    cout << sizeof(size_t) << endl;
}
