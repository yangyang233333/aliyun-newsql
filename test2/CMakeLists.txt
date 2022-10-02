cmake_minimum_required(VERSION 3.1)
project("interface")
set(CMAKE_CXX_STANDARD 14)

add_compile_options(-march=native -ffast-math)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Werror -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

# 设置头文件搜索目录
include_directories(../src)


file(GLOB_RECURSE SRC ../src/*.cpp) # 找出源文件
add_library(${PROJECT_NAME} SHARED ${SRC}) # 编译成动态库

find_library(LIB_PMEM pmem)
target_link_libraries(${PROJECT_NAME} ${LIB_PMEM}) # 链接

add_executable(main test_main.cpp)
target_link_libraries(main ${PROJECT_NAME})
