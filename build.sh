#主要用来测试当前目录中的CMakeLists.txt是否可以正常运行
echo "开始build..."
cmake -S . -B build

echo "build完成，开始make..."
cmake --build build

echo "make完成，开始清理文件"
rm -rf build/[A-Za-z]*