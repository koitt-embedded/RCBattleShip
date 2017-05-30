#include <sys/stat.h> 
#include <arpa/inet.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
 
#define MAXBUF    1024 
 
int main(int argc, char **argv) 
{ 
    struct sockaddr_in serveraddr; 
    int server_sockfd; 
    int client_len; 
    char buf[MAXBUF]; 
    char rbuf[MAXBUF]; 
 
 
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        perror("error :"); 
        exit(0); 
    } 
 
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    serveraddr.sin_family = AF_INET; 
    serveraddr.sin_addr.s_addr = inet_addr("192.168.0.26"); 
    serveraddr.sin_port = htons(atoi(argv[1])); 
 
    client_len = sizeof(serveraddr); 
 
    if (connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len) < 0) 
    { 
        perror("connect error :"); 
        exit(0); 
    } 
 
    while(1)
    {
        memset(buf, 0x00, MAXBUF); 
        read(0, buf, MAXBUF); 
        if (write(server_sockfd, buf, MAXBUF) <= 0) 
        { 
            perror("write error : "); 
            break;
        } 
        memset(buf, 0x00, MAXBUF); 
        if (read(server_sockfd, buf, MAXBUF) <= 0) 
       { 
           perror("read error : "); 
           break;
        }
        printf("read : %s", buf); 
    } 
    close(server_sockfd); 
    return 0;
}
