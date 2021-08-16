#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "错误使用文件! " << endl;
        cout << "例: ./server port" << endl;
    }

    struct sockaddr_in local;

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1)
    {
        perror("socket");
        return -1;
    }

    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY); // 任意ip
    local.sin_port = htons(atoi(argv[1]));

    // 绑定
    if (bind(listenfd, (struct sockaddr *)&local, sizeof(local)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;  
    }

    // 监听
    if (listen(listenfd, 5) < 0)
    {
        perror("listen");
        return -1;
    }

    // 接受客户端连接
    int clientfd;                             // 客户端的socket
    int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in 大小
    struct sockaddr_in clientaddress;
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddress, (socklen_t *)&socklen);
    cout << "客户端: " << inet_ntoa(clientaddress.sin_addr) << " 已连接!" << endl;

    // 开始与其通信
    char content[1024];
    while (true)
    {
        int iret;
        memset(content, 0, sizeof(content));
        if ((iret = recv(clientfd, content, sizeof(content), 0)) <= 0)
        {
            cout << "iret: " << iret << endl;
            return -1;
        }
        cout << "接收: " << content << endl;

        strcpy(content, "接收成功");
        if ((iret = send(clientfd, content, sizeof(content), 0)) <= 0)
        {
            perror("send");
            return -1;
        }
        cout << "发送: " << content << endl;
    }

    // 释放资源
    close(listenfd);
    close(clientfd);

    return 0;
}