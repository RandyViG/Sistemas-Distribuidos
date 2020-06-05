#include <iostream>
#include <cstring>
#include "SocketMulticast.h"

using namespace std;

#define SEGUNDOS 2
#define MILISEGUNDOS 500000

int main(int argc, char* argv[]){
    if(argc != 3) {
		printf("Uso: %s IPmulticast puerto\n", argv[0]);
		exit(0);
	}
    int nb=0,res;
    struct mensaje msj;
    int puerto = atoi(argv[2]);
    SocketMulticast sm( puerto );
    sm.unirseGrupo( argv[1] );
    PaqueteDatagrama recibe = PaqueteDatagrama( sizeof(msj) );
    while( true ){
        if( sm.recibeConfiable( recibe ) != -1 ){
            memcpy(&msj,recibe.obtieneDatos(),recibe.obtieneLongitud());
            nb += *msj.arguments;
        }
        printf("Valor en la cuenta: %d\n",nb);
    }
}