#include <iostream>
#include <stdio.h>
#include <string.h>
#include "SocketDatagrama.h"
#include "SocketMulticast.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3) {
		printf("Uso: %s IPmulticast puerto \n", argv[0]);
		exit(0);
	}
    char numeros[2],suma;
    int port = atoi(argv[2]);
    SocketMulticast s(port);
    SocketDatagrama sd(0);
    PaqueteDatagrama recibe = PaqueteDatagrama( 2 );
    s.unirseGrupo( argv[1] );
    if( s.recibe( recibe ) ){
        cout << "\nMensaje recibido de:" << endl;
        printf("IP: %s\n",recibe.obtieneDireccion() );
        printf("Puerto: %d\n",recibe.obtienePuerto() );
        printf("Longitud: %d\n",recibe.obtieneLongitud() );
		memcpy(numeros, recibe.obtieneDatos(), recibe.obtieneLongitud());
        suma = numeros[0]+ numeros[1];
        printf("Suma: %d + %d = %d\n",numeros[0],numeros[1],suma);
        PaqueteDatagrama respuesta(&suma,1,recibe.obtieneDireccion(),2700);
        sd.envia(respuesta);
    }
    s.salirseGrupo( argv[1] );
    return 0;
}