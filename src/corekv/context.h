//
// Created by qianyy on 10/3/22.
//

#ifndef INTERFACE_CONTEXT_H
#define INTERFACE_CONTEXT_H

#include <atomic>
#include <string>
#include <string.h>

using std::atomic;
namespace corekv {
    //Context的定义
    class Context {
    public:
        Context() = default;

        void parse_file_to_get_offset();

        int32_t get_offset() {
            return offset++;
        }

    public:
        //PMEM文件相关
        std::string filepath; //PMEM文件的路径，例如/mnt/aep/file1
        char *fileaddr = nullptr;   //PMEM文件地址
        size_t file_size = 0; //开辟55GB的大小，所以是55*1024*1024*1024
        size_t mapped_len = 0;
        int is_pmem = 0;

        //下一条数据应该写入的位置，初始化时为0。
        atomic<int32_t> offset{0};
    };


}

#endif //INTERFACE_CONTEXT_H
