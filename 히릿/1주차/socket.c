#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    // socket() -> ������ ����� �ý��� ��, �̸� ���¸� ����ִ� ��

    int socket_descriptor;

    // ������������ ��� ���� ���Ϸ� ����ϱ� ������ ���� ���� ���Ϸ� ��޵ȴ�
    // �׷��� ������ ������ �����ϸ� ���� ���� ���� ��ũ���Ͱ� �ȴ�
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    return 0;
}