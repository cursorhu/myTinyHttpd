#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A'; 

    if(argc < 3)
    {
        printf("usage: ./client <server_addr> <server_port>\n");
        return -1;
    }
        
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(argv[1]); //让用户输入server的addr和port, 若server在本地：127.0.0.1
    address.sin_port = htons(atoi(argv[2])); //server httpd的前向端口
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);

    if (result == -1)
    {
        perror("oops: client connect fail!\n");
        exit(1);
    }
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1); //阻塞直到server返回socket数据
    printf("char from server = %c\n", ch);
    close(sockfd);
    exit(0);
}
