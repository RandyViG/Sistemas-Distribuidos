#include <iostream>
#include <cstring>
#include "Respuesta.h"

using namespace std;

Respuesta :: Respuesta( int pto ) {
    socketlocal = new SocketDatagrama( pto );
}

struct mensaje * Respuesta :: getRequest( void ){
    struct mensaje datos,*aux;
    PaqueteDatagrama mensaje = PaqueteDatagrama( sizeof(datos) );
    if(socketlocal ->recibe(mensaje)){
        memcpy(&datos,mensaje.obtieneDatos(),sizeof(datos));
        memcpy(ip,mensaje.obtieneDireccion(),16);
        ptoDestino = mensaje.obtienePuerto();
    }
    aux = &datos;
    return aux;
}

void Respuesta :: sendReply( char *respuesta ){
    struct mensaje datos;
    datos.messageType = 0;
    datos.operationId = 1;
    datos.requestId = 1;
    memcpy( datos.arguments , respuesta , sizeof(respuesta) );

    PaqueteDatagrama dat = PaqueteDatagrama( (char *)&datos, sizeof(datos), ip , ptoDestino );
    socketlocal->envia(dat);
}