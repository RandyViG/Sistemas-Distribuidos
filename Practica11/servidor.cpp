#include "Respuesta.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int pto = 7300;
    Respuesta res( pto );
    struct mensaje *datos;
    char val[2],resultado;

    printf("\n********** Servidor iniciado **********");
    printf("\nEsperando mensajes en el puerto: %d\n",pto);
    
    while(1) {
        datos = res.getRequest( );
        memcpy(val,datos->arguments,2);
        resultado = val[0] + val[1];
        printf("\nMessage Type: %d",datos->messageType);
        printf("\nOperation ID: %d",datos->operationId);
        printf("\nValalores: %d  %d",val[0],val[1]);
        printf("\nResultado: %d \n", resultado);
        res.sendReply( &resultado );
    }
}