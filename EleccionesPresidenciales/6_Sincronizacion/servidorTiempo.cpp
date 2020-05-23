#include "Respuesta.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/time.h>

using namespace std;

int main( int argc , char *argv[] ){
    if( argc != 2 ){
        printf("Uso: %s pto \n" , argv[0]);
        exit(0);
    }
    int pto = atoi(argv[1]);
    Respuesta res( pto );
    struct mensaje datos;
    struct timeval timestamp, currently ;

    printf("\n********** Servidor de Tiempo iniciado **********");
    printf("\nServicio iniciado en el puerto: %d\n",pto);
    
    while(1) {
        memcpy( &datos, res.getRequest( ) , sizeof(datos) );
        if( res.getError() == 0 ){
            gettimeofday( &currently , NULL );
            printf("Timestamp %d - %d\n", timestamp.tv_sec, timestamp.tv_usec);
            memcpy( &timestamp , datos.arguments , sizeof(timestamp) );
        }
        res.sendReply( (char*)&currently );
    }
}
