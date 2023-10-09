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
    server_address.sin_port = htons(80); // �� ���� ��Ʈ�� 80

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    listen(server_socket, 5);

    printf("Server: Listening on port 80...\n");

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_addrlen = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_addrlen);

        // ��Ƽ ���μ��� �۾��� ���� ���� ������ ��ȭ
        if (fork() == 0) { // �ڽ� ���μ��� <- �� �κп� ����!

            printf("Server: Accepted connection from %s:%d\n",
                inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            // 3-way handshake�� ������ �� �ܰ� ����
            // ���⼭�� ACK�� ������ ������ ������ �����ݴϴ�.
            sleep(1); // �����δ� �ʿ��� ���� ����

            // ������ ���� ����
            char response[] = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
            send(client_socket, response, strlen(response), 0);
            printf("Server: Sent response to client.\n");

            close(client_socket);
            exit(0);
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}