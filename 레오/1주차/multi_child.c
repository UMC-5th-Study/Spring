#include <stdio.h>
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
        struct sockaddr_in client_address;
        socklen_t client_addrlen = sizeof(client_address);
				//부모 프로세스는 
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addrlen);

				//생성된 자식 프로세스의 pid는 0
        if (fork() == 0 -> true) { // 자식 프로세스가 실행할 코드


            printf("Server: Accepted connection from %s:%d\n",
                   inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            // 3-way handshake의 나머지 두 단계 수행
            // 여기서는 ACK를 보내는 과정만 간단히 보여줍니다.
            sleep(1); // 실제로는 필요한 로직 수행

            // 서버의 응답 전송
            char response[] = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
            send(client_socket, response, strlen(response), 0);
            printf("Server: Sent response to client.\n");

            close(client_socket);
						//자식 프로세스는 응답을 전송하고 종료됨
            exit(0); <-여기서 자식 프로세스가 종료됨
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}