
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

    // socket() == 소켓 생성 함수. 틀을 미리 만들어두는 것. 

    int socket_descriptor;
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    
    return 0;
}
