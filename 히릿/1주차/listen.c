#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // ... 서버 소켓의 주소와 바인딩 설정 ...

    // backlog에는 클라이언트의 요청 정보가 저장된다
    int backlog = 10; // 최대 대기열 크기

    // listen() 시스템 콜을 통해 클라이언트로부터 SYN 요청을 받기 위해 대기 상태로 기다린다
    // SYN -> SYN,ACK -> ACK 과정을 겪는 3-way handshake는 연결지향인 TCP의 특징이기 때문에, listen() 시스템콜은 연결지향인 TCP에서만 사용한다
    if (listen(sockfd, backlog) == -1) {
        perror("Listen failed");
        return 1;
    }

    // 리스닝 성공 처리 및 연결 요청 처리

    return 0;
}