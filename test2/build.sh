#本文件作用：使用test_main.cpp用来测试整个动态库
rm -rf build
cmake -S . -B build
#cmake --build build/
cmake --build build --target all -- -j4 # 4线程编译