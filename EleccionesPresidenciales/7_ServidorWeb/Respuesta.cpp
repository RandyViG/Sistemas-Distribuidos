#include <iostream>
#include <cstring>
#include "Respuesta.h"

using namespace std;

Respuesta :: Respuesta( int pto ) {
    socketlocal = new SocketDatagrama( pto );
}

int Respuesta :: getError( void ){ return error; }

struct mensaje * Respuesta :: getRequest( void ){
    struct mensaje datos,*aux;
    PaqueteDatagrama mensaje = PaqueteDatagrama( sizeof(datos) );
    if(socketlocal ->recibe(mensaje)){
        memcpy(&datos,mensaje.obtieneDatos(),sizeof(datos));
        memcpy(ip,mensaje.obtieneDireccion(),16);
        ptoDestino = mensaje.obtienePuerto();
        if( datos.requestId < id )
            error = 1;
        else{
            id++;
            error = 0;
        }
    }
    aux = &datos;
    return aux;
}

void Respuesta :: sendReply( char *respuesta ){
    struct mensaje datos;
    datos.messageType = 1;
    datos.operationId = 1;
    datos.requestId = id;
    memcpy( datos.arguments , respuesta , sizeof(datos.arguments) );
    PaqueteDatagrama dat = PaqueteDatagrama( (char *)&datos, sizeof(datos), ip , ptoDestino );
    socketlocal->envia(dat);
}