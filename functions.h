#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>


// Variables Globales
#define BUFFER_SIZE 512

// Functions
int RRQ_rqst(char * file, char * port, char * host, char * frame, int sock, struct sockaddr_in addr);
char RRQ_recept(int sock, char * frame, struct sockaddr_in addr);