#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(80);

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    listen(server_socket, 5);

    printf("Server: Waiting for client's connection...\n");

    struct sockaddr_in client_address;
    socklen_t client_addrlen = sizeof(client_address);

    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addrlen);

    printf("Server: Accepted connection from %s:%d\n",
           inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // 3-way handshake의 나머지 두 단계 수행.  
    // 과정 중 client가 보내는 SYN은 listen 상태인 서버의 소켓에 연결 요청 하는 것.
    // 이후 남은 두 단계는 accept 시스템 콜 이후 진행. 

    char buffer[1024];
    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0); // 클라이언트의 ACK 받기

    if (bytes_received > 0) {
        printf("Server: Received ACK from client.\n");
        
    }