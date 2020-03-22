#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int puerto = 7200;

int main( int argc, char *argv[] ) {

   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res,i;
   unsigned char s_addr[4],IP[16];

   strcpy(IP, argv[1]);
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(IP);
   memcpy(s_addr,&msg_to_server_addr.sin_addr.s_addr,4);
   for(i = 0; i < 4 ; i++)
      printf("%d ",s_addr[i]);
   printf("\n");
   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   client_addr.sin_port = htons(0); //El sistema asigna el puerto
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2*sizeof(int), 0, (struct sockaddr*)&msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   memcpy(s_addr,&msg_to_server_addr.sin_addr.s_addr,4);
   printf("\nRecibido desde:");
   printf("\nIP: %d.%d.%d.%d",s_addr[0],s_addr[1],s_addr[2],s_addr[3]);
   printf("\nPuerto: %d",ntohs(msg_to_server_addr.sin_port) );
   printf("\n2 + 5 = %d\n", res);
   close(s);
}

