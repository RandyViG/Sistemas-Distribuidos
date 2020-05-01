#include "Respuesta.h"
#include "registro.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main( int argc , char *argv[]){
    if( argc != 2 ){
        printf("Uso: %s Nombre_Archivo \n" , argv[0]);
        exit(0);
    }
    int pto = 7300;
    Respuesta res( pto );
    struct mensaje datos;
    struct registro reg;
    char argument[]= {"OK"};

    int archivo;
    string aux;

    printf("\n********** Servidor iniciado **********");
    printf("\nEsperando mensajes en el puerto: %d\n",pto);
    
    while(1) {
        memcpy( &datos,res.getRequest( ),sizeof(datos) );
        if( res.getError() == 0 ){
            memcpy( &reg , datos.arguments , sizeof(datos.arguments) );
            printf("Registro exitoso  \nCel: %s\n",reg.celular);
            printf("CURP: %s\n",reg.CURP);
            printf("Partido: %s\n\n",reg.partido);
            aux = reg.toString() + "\n";
            if( ( archivo = open(argv[1], O_WRONLY |O_CREAT|O_APPEND,0666) ) )
                perror(argv[1]);
	        write( archivo , aux.c_str() , 32);
	        fsync( archivo );
            close( archivo );
        }
        res.sendReply( (char*)&argument );
    }
}