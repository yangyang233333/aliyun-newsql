#include "interface.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class User {
public:
    int64_t id;
    char user_id[128];
    char name[128];
    int64_t salary;
};

enum Column {
    Id = 0, Userid, Name, Salary
};

std::vector<User> users;

void engine_write(void *ctx, const void *data, size_t len) {

}

size_t engine_read(void *ctx, int32_t select_column,
                   int32_t where_column, const void *column_key, size_t column_key_len, void *res) {
    return 0;
}

void *engine_init(const char *host_info, const char *const *peer_host_info, size_t peer_host_info_num,
                  const char *aep_dir, const char *disk_dir) {

    /*
 * Initialization interface, which is called when the engine starts.
 * You need to create or recover db from pmem-file.
 * host_info: Local machine information including ip and port. This value is nullptr in the preliminary round.
 * peer_host_info: Information about other machines in the distributed cluster. This value is nullptr in the preliminary round.
 * peer_host_info_num: The num of other machines in the distributed cluster.  This value is 0 in the preliminary round.
 * aep_dir: AEP file directory, eg : "/mnt/aep/"
 * disk_dir: Disk file directory, eg : "/mnt/disk/"
 */
    string HOST_INFO = host_info;

    string AEP_DIR = aep_dir;
    string DISK_DIR = disk_dir;
    size_t PEER_HOST_INFO_NUM = peer_host_info_num;

    cout << "HOST_INFO=" << HOST_INFO << ", AEP_DIR=" << AEP_DIR << ", DISK_DIR=" << DISK_DIR << ", PEER_HOST_INFO_NUM="
         << PEER_HOST_INFO_NUM << endl;
    for (size_t i = 0; i < peer_host_info_num; ++i) {
        cout << "第 [" << i << "] 次：" << peer_host_info[i] << endl;
    }

    return nullptr;
}

void engine_deinit(void *ctx) {

}
