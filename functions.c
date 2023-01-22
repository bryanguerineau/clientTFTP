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
    
    printf("Execution correcte de RRQ_rqst \n");

    return 0;
}

char RRQ_recept(int sock, char * frame, struct sockaddr_in addr){
    /*
    
    */
   int recept_bytes = recvfrom(sock, frame, sizeof(frame), 0, &addr, sizeof(addr));

   char byte2 = frame[2];
   char byte3 = frame[3];
   short blockNum = (byte2 << 8) | byte3;

   printf("Execution correcte de RRQ_recept %d \n", recept_bytes);
   printf("Numéro de block : %d\n", blockNum);

}