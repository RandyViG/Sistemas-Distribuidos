#include "Respuesta.h"
#include "Solicitud.h"
#include "registro.h"
#include "trie.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/time.h>

using namespace std;

int main( int argc , char *argv[] ){
    if( argc != 5 ){
        printf("Uso: %s ptoLocal IpTiempo PtoTiempo Nombre_Archivo \n" , argv[0]);
        exit(0);
    }
    int pto = atoi(argv[1]);
    Respuesta res( pto );
    Solicitud tiempo;
    struct mensaje datos;
    struct registro reg;
    struct timeval timestamp;
    struct TrieNode *trie = getNode();
    int archivo,ptoTime = atoi( argv[3] );
    string aux;

    printf("\n********** Servidor iniciado **********");
    printf("\nEsperando mensajes en el puerto: %d\n",pto);
    
    while(1) {
        memcpy( &datos,res.getRequest( ),sizeof(datos) );
        if( res.getError() == 0 ){
            memcpy( &timestamp , tiempo.doOperation(argv[2],ptoTime,0,(char*)&timestamp) , sizeof(timestamp) );
            memcpy( &reg , datos.arguments , sizeof(datos.arguments) );
            if ( !search( trie , string(reg.celular) ) ){
                insert( trie , string(reg.celular) );
                printf("Registro exitoso  \nCel: %s\n",reg.celular);
                printf("CURP: %s\n",reg.CURP);
                printf("Partido: %s\n",reg.partido);
                printf("timestamp: %d - %d \n\n",timestamp.tv_sec,timestamp.tv_usec);
                aux = reg.toString() + " " 
                    + to_string(timestamp.tv_sec) + "-" 
                    + to_string(timestamp.tv_usec) +  "\n";
                if( ( archivo = open(argv[4], O_WRONLY |O_CREAT|O_APPEND,0666) ) == -1 )
                    perror(argv[4]);
	            write( archivo , aux.c_str() , aux.length() );
	            fsync( archivo );
                close( archivo );
            }
            else{
                timestamp.tv_sec = 0;
                timestamp.tv_usec = 0;
            }
        }
        res.sendReply( (char*)&timestamp );
    }
}