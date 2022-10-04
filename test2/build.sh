#本文件作用：使用test_main.cpp用来测试整个动态库
rm -rf build
sudo rm -rf /mnt/aep/*

cmake -S . -B build
cmake --build build --target all -- -j4 # 4线程编译

echo "开始运行... ..."
sudo ./build/test_main