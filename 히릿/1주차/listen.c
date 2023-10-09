#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // ... ���� ������ �ּҿ� ���ε� ���� ...

    // backlog���� Ŭ���̾�Ʈ�� ��û ������ ����ȴ�
    int backlog = 10; // �ִ� ��⿭ ũ��

    // listen() �ý��� ���� ���� Ŭ���̾�Ʈ�κ��� SYN ��û�� �ޱ� ���� ��� ���·� ��ٸ���
    // SYN -> SYN,ACK -> ACK ������ �޴� 3-way handshake�� ���������� TCP�� Ư¡�̱� ������, listen() �ý������� ���������� TCP������ ����Ѵ�
    if (listen(sockfd, backlog) == -1) {
        perror("Listen failed");
        return 1;
    }

    // ������ ���� ó�� �� ���� ��û ó��

    return 0;
}