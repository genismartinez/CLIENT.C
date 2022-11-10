/* Inclusio de fitxers .h habituals */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* Inclusio de fitxers .h per als sockets */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define MIDA_BUFFER 1024
 
int main(int argc, char **argv){
 
    if (argc != 2) {
        printf("Us: %s IP\n", argv[0]);
        exit(0);
    }
    
    int s;    /* Per treballar amb el socket */
    struct sockaddr_in adr;
    char buffer[MIDA_BUFFER];
    int i;
    int n1, n2;
    char value1,value2; 
    int multiplicacio;
    int elems=3;
    const char *a[elems];
    printf("%s\n",argv[1]);
printf("Introdueix el primer nombre:");
scanf("%d", &n1);
 
printf("Introdueix el segon nombre:");
    scanf("%d", &n2);
    
    sprintf(buffer,"%d %d", n1,n2);
    
    printf("%s\n",buffer);
 
        //printf("el valor de la multiplicació es %d.", resultat);
        
        int val= atoi(*a);
        printf("val = %d", val);
    /* Volem socket d'internet i no orientat a la connexio */
    s = socket(AF_INET, SOCK_DGRAM, 0);
 
    adr.sin_family = AF_INET;
    adr.sin_port = htons(44444);
 
    /* L'adreca de comunicacio sera la IP del servidor, es a dir el parametre */
    adr.sin_addr.s_addr = inet_addr(argv[1]);
 
    /* Generem 5 paquets i els enviem */
    /*for (i = 0; i < 5; i++)
    {
        buffer[0] = i + '0';
        buffer[1] = '\0';
        printf("%s",buffer);*/
        sendto(s, buffer, MIDA_BUFFER, 0, (struct sockaddr*)&adr, sizeof(adr));
 
        printf("Paquet enviat!\n");
 
    //}
 
    printf("Esperant resultat del servidor!\n");
    recvfrom(s, buffer, MIDA_BUFFER,0, NULL, NULL);
    printf("La resposta del server es --> %s\n", buffer);
 
    /* Tanquem el socket */
    close(s);
    return 0;
}
