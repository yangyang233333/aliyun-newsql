//
// Created by qianyy on 10/3/22.
//

#ifndef INTERFACE_API_H
#define INTERFACE_API_H

#include <string>
#include <iostream>
#include <string.h>
#include "common.h"

namespace corekv {

    extern void engine_write(void *ctx,
                             const void *data,
                             size_t len);

    extern size_t engine_read(void *ctx,
                              int32_t select_column,
                              int32_t where_column,
                              const void *column_key,
                              size_t column_key_len,
                              void *res);

    extern void *engine_init(const char *host_info,
                             const char *const *peer_host_info,
                             size_t peer_host_info_num,
                             const char *aep_dir,
                             const char *disk_dir);

    extern void engine_deinit(void *ctx);

}


#endif //INTERFACE_API_H
