#include "SocketDatagrama.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main( int argc , char *argv[]){
    if( argc != 2 ){
        printf("Uso: %s Nombre_Archivo \n" , argv[0]);
        exit(0);
    }
    int pto = 7300, archivo;
    char argument[]= {"OK"};
    SocketDatagrama servidor(pto);
    PaqueteDatagrama p(34);
    printf("\n********** Servidor iniciado **********");
    printf("\nEsperando mensajes en el puerto: %d\n",pto);
    
    while(1) {
        if( servidor.recibe(p) ){
            printf("Recibiendo registro");
            printf("IP: %s\n", p.obtieneDireccion());
            printf("Puerto: %d\n",p.obtienePuerto());
            printf("Registros %s\n",p.obtieneDatos());
            if( ( archivo = open(argv[1], O_WRONLY |O_CREAT|O_APPEND,0666) ) )
                perror(argv[1]);
	        write( archivo , p.obtieneDatos() , 32);
	        fsync( archivo );
            close( archivo );
        }
    }
}