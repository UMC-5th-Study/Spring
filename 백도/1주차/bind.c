#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;         // IPv4 주소 체계
    server_address.sin_addr.s_addr = INADDR_ANY; // 모든 가능한 IP 주소
    server_address.sin_port = htons(80);       // 포트 번호 80

    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        return 1;
    }

    // 바인딩 성공 처리 및 작업 수행

    return 0;
}