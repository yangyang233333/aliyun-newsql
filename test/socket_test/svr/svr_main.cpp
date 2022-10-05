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
#include <cctype>

int main(int argc, char *argv[]) {
    // 1.创建socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket建立失败");
    }

    sockaddr_in svr_addr;
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_port = htons(9527);
    svr_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 2.
    bind(fd, (sockaddr *) &svr_addr, sizeof(svr_addr));

    // 3.设置最大连接数
    listen(fd, 128);

    // 4.
    sockaddr cli_addr;
    socklen_t cli_addr_len;
    cli_addr_len = sizeof(cli_addr);
    int new_fd = accept(fd, (sockaddr *) &cli_addr, &cli_addr_len);
    if (new_fd == -1) {
        perror("accept error");
    }

    // 5.
    char buf[BUFSIZ];
    while (true) {
        //ret是实际读取到的字节数
        int ret = read(new_fd, buf, sizeof(buf));

        for (int i = 0; i < ret; ++i) {
            buf[i] = toupper(buf[i]);
        }
        //转为大写后，返回给客户端
        write(new_fd, buf, ret);
    }


    close(fd);
    close(new_fd);

    return 0;
}
