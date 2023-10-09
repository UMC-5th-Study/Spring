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

    // bind() -> 생성한 소켓에 실제 아이피 주소와 포트번호를 부여하는 시스템 콜
    // 클라이언트는 통신 시 자동으로 OS에서 포트번호를 부여하기 때문에 bind() 시스템 콜은 서버에서만 사용
    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        return 1;
    }

    // 바인딩 성공 처리 및 작업 수행

    return 0;
}