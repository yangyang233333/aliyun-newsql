//
// Created by qianyy on 10/3/22.
//

#include "context.h"
#include "utils/checksum.h"

namespace corekv {
    void Context::parse_file_to_get_offset() {
        int32_t _offset = 0;
        //todo:实际上没有必要每次init的时候都全表扫描，需要优化：例如及时终止循环
        //todo:多线程扫描建立索引
        for (size_t i = 0; i < 2L * 10000 * 10000 + 1000L; ++i) {
            int64_t id, checksum;
            memcpy(&id, this->fileaddr + i * 280L, 8);
            memcpy(&checksum, this->fileaddr + i * 280L + 272, 8);
            int64_t checksum_val = check_sum(id);

            if (checksum == checksum_val) {
                _offset = i + 1;
                continue;
            } else {
                //有以下几种可能：
                //1. 写入的时候被kill，此时checksum=0或者checksum=随机数
                //2. 从来没有写到过这里，此时checksum=0

                //进行一下检查，如果是情况2可以直接中断循环，如果是情况1则不能
                //设置一个循环，向后扫描1000个，看看有没有数据
                bool has_data = false;
                for (size_t j = i + 1; j < i + 1 + 1000; ++j) {
                    int64_t test_id;
                    memcpy(&test_id, this->fileaddr + j * 280, 8);
                    if (test_id != 0) {
                        has_data = true;
                        break;
                    }
                }
                if (!has_data) {
                    break;
                }
            }
        }

        this->offset = _offset;
    }
}
