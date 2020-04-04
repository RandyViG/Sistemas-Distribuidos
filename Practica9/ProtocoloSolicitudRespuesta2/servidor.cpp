#include "Respuesta.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int pto = 7300;
    Respuesta res( pto );
    struct mensaje datos;
    int deposito,nbd = 0;

    printf("\n********** Servidor iniciado **********");
    printf("\nEsperando mensajes en el puerto: %d\n",pto);
    
    while(1) {
        memcpy(&datos,res.getRequest(),sizeof(datos));
        if( res.getError() == 0 ){
            memcpy(&deposito,datos.arguments,4);
            nbd += deposito;
            printf("\nCuenta: %d \n", nbd);
        }
        res.sendReply( (char*)&nbd );
    }
}