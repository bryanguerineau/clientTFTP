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

    // Envoie de la requête avec sendto
    sendto(sock, frame, sizeof(frame), 0, (struct sockaddr *)&addr, sizeof(addr));

    return 0;
}