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

void ServerProcess(void) {
    int serverSockfd = -1;
    int acceptSockfd = -1;
    socklen_t addrLen = 0;
    char recvBuf[1024] = {0};
    int recvLen = 0;

    struct sockaddr_in tSocketServerAddr;
    struct sockaddr_in tSocketClientAddr;

    tSocketServerAddr.sin_family = AF_INET;
    tSocketServerAddr.sin_port = htons(SERVER_PORT);
    tSocketServerAddr.sin_addr.s_addr = htons(INADDR_ANY);

    /* 1. 创建socket */
    serverSockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == serverSockfd) {
        handle_error("socket");
    }

    /* 2. 绑定socket	 */
    if (-1 == bind(serverSockfd, (struct sockaddr *) &tSocketServerAddr, sizeof(struct sockaddr_in))) {
        handle_error("bind");
    }

    /* 3. 监听   */
    if (-1 == listen(serverSockfd, LISTEN_BACKLOG)) {
        handle_error("listen");
    }

    while (1) {
        addrLen = sizeof(struct sockaddr);
        acceptSockfd = accept(serverSockfd, (struct sockaddr *) &tSocketClientAddr, &addrLen);

        if (-1 != acceptSockfd) {
            printf("Connected Client IP : %s  \n", inet_ntoa(tSocketClientAddr.sin_addr));
            printf("Waiting client send message...\n");

            /* 创建子进程,用于多个client连接	*/
            if (0 == fork()) {
                while (1) {
                    /* 阻塞接收客户端数据, 收到后返回,并打印 */
                    recvLen = recv(acceptSockfd, recvBuf, 1023, 0);

                    if (recvLen <= 0) {
                        close(acceptSockfd);
                        return;
                    } else {
                        recvBuf[recvLen] = '\0';
                        printf("Client: %s\n", recvBuf);
                    }
                }
            }
        } else {
            handle_error("accept");
        }
    }
    close(serverSockfd);
    serverSockfd = -1;
}

int main(int argc, char *argv[]) {
    ServerProcess();
    return 0;
}
