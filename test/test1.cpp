//
// Created by qianyangyang on 9/25/22.
//

#include <iostream>
#include <functional>
#include <string>

int main()
{
    std::string str = "Meet the new boss...";
    std::hash<std::string> hash_fn;
    size_t str_hash = hash_fn(str);

    std::cout << str_hash << '\n';
}

//#include <iostream>
//#include <functional>
//#include <string>
//
//int main(int argc, char *argv[]) {
//    std::hash <std::string> h;
//    size_t n = h("aaaaaaaaaa");
//    std::cout << n << std::endl;
//
//    return 0;
//}