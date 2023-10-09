#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // ... 서버 소켓의 주소와 바인딩 설정 ...

    /*listen 시스템콜을 통해서 tcp를 대기 상태로 만들고
    클라이언트가 서버에 syn 패킷을 전송하는 연결 요청을 받아둘 백로그 큐를 만들어 둔다*/

    int backlog = 10; // 최대 대기열 크기
    if (listen(sockfd, backlog) == -1) {
        perror("Listen failed");
        return 1;
    }

    // 리스닝 성공 처리 및 연결 요청 처리

    return 0;
}