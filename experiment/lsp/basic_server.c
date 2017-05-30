#include <sys/socket.h> 
#include <sys/stat.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
 
#define MAXBUF  256

int main(int argc, char **argv) 
{ 
    int server_sockfd, client_sockfd; 
    int client_len, n; 
    char buf[MAXBUF]; 
    struct sockaddr_in clientaddr, serveraddr; 
 
    client_len = sizeof(clientaddr); 

    // 소켓 만들기   
    if ((server_sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        perror("socket error : "); 
        exit(0); 
    } 

    // 소켓에 주소를 묶는다.
    bzero(&serveraddr, sizeof(serveraddr)); 
    serveraddr.sin_family = AF_INET; 
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]); 
    serveraddr.sin_port = htons(atoi(argv[2])); 
    bind (server_sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)); 

    // 소켓 연결 대기열을 만든다.
    listen(server_sockfd, 5); 
 
    while(1) 
    { 
        memset(buf, 0x00, MAXBUF); 
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr, &client_len); 
        while(1)
        {
            if ((n = read(client_sockfd, buf, MAXBUF)) <= 0) 
            { 
                close(client_sockfd); 
                break;
            } 
            if (write(client_sockfd, buf, MAXBUF) <=0) 
            { 
                perror("write error : "); 
                close(client_sockfd); 
                break;
            } 
        }
        close(client_sockfd); 
    } 
}
