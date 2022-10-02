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

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5001
#define LISTEN_BACKLOG 50

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)


void ClientProcess(void) {
    int clientSockfd = -1;

    struct sockaddr_in socketServerAddr;
    char sendBuf[1024] = {0};
    int sendLen = 0;

    /* 1. 创建socket	 */
    clientSockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == clientSockfd) {
        handle_error("socket");
    }

    socketServerAddr.sin_family = AF_INET;
    socketServerAddr.sin_port = htons(SERVER_PORT); /* host to net, short */

    /* 2. 转换server ip为网络字节序	 */
    if (0 == inet_aton(SERVER_IP, &socketServerAddr.sin_addr)) {
        printf("Server ip error\n");
        return;
    }

    /* 3. 连接server	 */
    if (-1 == connect(clientSockfd, (const struct sockaddr *) &socketServerAddr, sizeof(struct sockaddr))) {
        handle_error("connect");
    } else {
        printf("Connect success.\nPlease input message:\n");
    }

    /* 4. 循环输入内容,并发送给server */
    while (1) {
        if (fgets(sendBuf, 1023, stdin)) {
            sendLen = send(clientSockfd, sendBuf, strlen(sendBuf), 0);

            if (sendLen <= 0) {
                close(clientSockfd);
                return;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ClientProcess();
    return 0;
}