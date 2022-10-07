#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // 1.创建socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket error");
    }

    // 2.连接服务器
    sockaddr_in svr_addr;
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_port = htons(9527);

    //将IP地址从字符串格式转换成网络地址格式，支持Ipv4和Ipv6
    inet_pton(AF_INET, "127.0.0.1", &svr_addr.sin_addr.s_addr);
    cout <<"aaaaaaaaaaaaaaaaaaaaa:"<< svr_addr.sin_addr.s_addr << endl;
    int ret = connect(fd, (sockaddr *) &svr_addr, sizeof(svr_addr));
    if (ret != 0) {
        perror("connect err");
    }

    // 3.写数据
    int cnt = 5;
    char buf[BUFSIZ];
    while (--cnt > 0) {
        write(fd, ("hello_" + to_string(cnt)).c_str(), ("hello_" + to_string(cnt)).size());
        int char_cnt = read(fd, buf, sizeof(buf));
        for (int i = 0; i < char_cnt; ++i) {
            cout << buf[i];
        }
        cout << endl;
    }

    close(fd);


    return 0;


}