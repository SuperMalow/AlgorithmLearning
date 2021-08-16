#include <iostream>
#include <cstring>
#include <unistd.h> // write  close  read
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

using namespace std;
// 49.235.236.22
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "错误使用" << endl;
        cout << "例: ./client ip port " << endl;
    }
    struct sockaddr_in address;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(argv[1]);
    address.sin_port = htons(atoi(argv[2]));

    int result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if (result != 0)
    {
        perror("connect");
        return -1;
    }
    char content[1024];
    int n = 3;
    while (cin >> content, strcmp(content, "exit") != 0)
    {
        // cout << "输入发送信息: " << endl;
        // cin >> content;

        int iret = send(sockfd, content, strlen(content), 0);
        if (iret <= 0)
        {
            perror("send");
            break;
        }
        cout << "发送: " << content << endl;

        memset(content, 0, sizeof(content));
        iret = recv(sockfd, content, sizeof(content), 0);
        if (iret <= 0)
        {
            cout << "iret = " << iret << endl;
            break;
        }
        cout << "接收: " << content << endl;

    }

    close(sockfd);

    return 0;
}