#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    // socket() -> 소켓을 만드는 시스템 콜, 미리 형태를 잡아주는 것

    int socket_descriptor;

    // 리눅스에서는 모든 것을 파일로 취급하기 때문에 소켓 역시 파일로 취급된다
    // 그렇기 때문에 소켓을 생성하면 리턴 값은 파일 디스크립터가 된다
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    return 0;
}