#include "functions.h"

int RRQ_rqst(char * file, char * port, char * host, char * frame, int sock, struct sockaddr_in addr){
    
    char * mode = "octet";

    /*
    2 bytes    string    1 byte     string   1 byte
    ------------------------------------------------
    | Opcode | Filename  |  0   |    Mode    |   0
    ------------------------------------------------
    */ 
    
    frame[0] = 0x00;
    frame[1] = 0x01; // '1' pour effetctuer une requête
    strcpy((char *)frame + 2, file);
    frame[strlen(file)+2] = 0x00;
    strcpy((char *)frame + 2 + 1, mode);
    frame[strlen(file)+ 2 + strlen(mode) + 1] = 0x00;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        perror("Erreur : socket");
        return EXIT_FAILURE;
    }
    // Envoie de la requête avec sendto
    int send_t = sendto(sock, frame, sizeof(frame), 0, (struct sockaddr *)&addr, sizeof(addr));
    
    printf("Execution correcte de RRQ_rqst \n");

    return 0;
}


int RRQ_recept(int sock, struct sockaddr_in addr, struct addrinfo *result){
    
    char data[BUFFER_SIZE];

    int recept_bytes = recvfrom(sock, data, sizeof(data), 0, result->ai_addr, &(result->ai_addrlen));

    unsigned char byte2 = data[2];
    unsigned char byte3 = data[3];
    unsigned short blockNum = (byte2 << 8) | byte3;

    printf("Execution correcte de RRQ_recept %d \n", recept_bytes);
    printf("Numéro de block : %d\n", blockNum);
    fprintf(stderr,"Opcode: %d,%d  Block %d,%d\nTaille des donnés: %d\n",data[0],data[1],data[2],data[3],recept_bytes-4);

    return EXIT_SUCCESS;
}
