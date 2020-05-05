#include "Respuesta.h"
#include "registro.h"
#include "trie.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/time.h>

using namespace std;

int main( int argc , char *argv[] ){
    if( argc != 2 ){
        printf("Uso: %s Nombre_Archivo \n" , argv[0]);
        exit(0);
    }
    int pto = 7300;
    Respuesta res( pto );
    struct mensaje datos;
    struct registro reg;
    struct timeval timestamp;
    struct TrieNode *trie = getNode();

    int archivo;
    string aux;

    //printf("\n********** Servidor iniciado **********");
    //printf("\nEsperando mensajes en el puerto: %d\n",pto);
    
    while(1) {
        memcpy( &datos,res.getRequest( ),sizeof(datos) );
        if( res.getError() == 0 ){
            gettimeofday( &timestamp , NULL );
            memcpy( &reg , datos.arguments , sizeof(datos.arguments) );
            if ( !search( trie , string(reg.celular) ) ){
                insert( trie , string(reg.celular) );
                //printf("Registro exitoso  \nCel: %s\n",reg.celular);
                //printf("CURP: %s\n",reg.CURP);
                //printf("Partido: %s\n\n",reg.partido);
                aux = reg.toString() + " " 
                    + to_string(timestamp.tv_sec) + "-" 
                    + to_string(timestamp.tv_usec) +  "\n";
                if( ( archivo = open(argv[1], O_WRONLY |O_CREAT|O_APPEND,0666) ) )
                    perror(argv[1]);
	            write( archivo , aux.c_str() , 50);
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