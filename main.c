#include "functions.h"

int main(int argc, char * argv[]){
    // Variables locales
    //char * host = argv[1];
    //char * file = argv[2];

    // Test functionality
    char * host = "127.0.0.1";
    char * file = "zeros256";
    char * port = "1069";

    struct addrinfo hints;
    struct addrinfo * result = NULL;
    struct sockaddr_in addr;

    char frame[BUFFER_SIZE + 4];
    int s;
    int sock;

    // creatiion de addrinfo
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;      /* Autorise IPv4 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_flags = 0;

    s = getaddrinfo(host, port, &hints, &result);

    if (s!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    } else {
        printf("Execution correcte de getaddrinfo \n");
    }

    int reqst_RRQ = RRQ_rqst(file, port, host, frame, sock, addr);

    RRQ_recept(sock, addr, result);


}