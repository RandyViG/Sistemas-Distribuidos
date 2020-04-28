#include <iostream>
#include <cstring>
#include "SocketMulticast.h"
#include "SocketDatagrama.h"
using namespace std;

#define SEGUNDOS 2
#define MILISEGUNDOS 500000

int main(int argc, char* argv[]){
    if(argc != 4) {
		printf("Uso: %s IP_Multicast puerto TTL\n", argv[0]);
		exit(0);
	}
    int port,TTL;
    port = atoi( argv[2] );
    TTL = atoi( argv[3] );
    char num[2] = { 4 , 5 },res;
    SocketMulticast s( port );
    SocketDatagrama sd( 2700 );
    PaqueteDatagrama enviar( num , 2 , argv[1] , port );
    PaqueteDatagrama recibe( 1 );
    while( true ){
        s.envia(enviar,TTL);
        if( sd.recibeTimeout(recibe,SEGUNDOS,MILISEGUNDOS)  != -1){
		    memcpy(&res, recibe.obtieneDatos(), recibe.obtieneLongitud());
            printf("Respuesta: %d\n", res);
            printf("Recibi de: %s\n", recibe.obtieneDireccion());
        }
    }
}