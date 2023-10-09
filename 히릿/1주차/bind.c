#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;         // IPv4 �ּ� ü��
    server_address.sin_addr.s_addr = INADDR_ANY; // ��� ������ IP �ּ�
    server_address.sin_port = htons(80);       // ��Ʈ ��ȣ 80

    // bind() -> ������ ���Ͽ� ���� ������ �ּҿ� ��Ʈ��ȣ�� �ο��ϴ� �ý��� ��
    // Ŭ���̾�Ʈ�� ��� �� �ڵ����� OS���� ��Ʈ��ȣ�� �ο��ϱ� ������ bind() �ý��� ���� ���������� ���
    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        return 1;
    }

    // ���ε� ���� ó�� �� �۾� ����

    return 0;
}