#include <stdio.h#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(80); // 웹 서버 포트인 80

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    listen(server_socket, 5);

    printf("Server: Listening on port 80...\n");

    while (1) {
				//부모 프로세스는 소켓 - bind - listen를 한 후에 무한루프로 accept로 요청을 받음
        struct sockaddr_in client_address;
        socklen_t client_addrlen = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addrlen);

			  //부모 프로세스의 pid는 0이 아님, if문 블록 내부를 실행안함
        if (fork() == 0 -> false ) { 
           실행안함
        }

      
    }

    close(server_socket);

    return 0;
	}