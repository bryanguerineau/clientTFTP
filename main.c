#include <stdio.h>
#include "functions.h"

int main(int argc, char * argv[]){
    // Variables locales
    char * host = argv[1];
    char * file = argv[2];
    char * port = "69";

    struct addrinfo hints;
    struct addrinfo * result = NULL;

    char frame[BUFFER_SIZE + 4];
    int s;

    // creatiion de addrinfo
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;      /* Autorise IPv4 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_protocol = IPPROTO_UDP;

    s = getaddrinfo(host, port, &hints, &result);
        

}