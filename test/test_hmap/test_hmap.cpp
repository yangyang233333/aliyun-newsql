#include<unordered_map>
#include <stdint.h>
#include <iostream>
#include <functional>
#include <string>
#include <stdint.h>

using namespace std;

struct KEY {
    int64_t k1;
    int64_t k2;
    int64_t k3;
    int64_t k4;
};

struct Hash {
    int64_t operator()(const KEY &key) const {
        return;
    }

};

int main() {
    std::function a;




}

