#include <iostream>
#include <cstring>
#include "Solicitud.h"
#include "mensaje.h"

using namespace std;

Solicitud :: Solicitud (){
    socketlocal = new SocketDatagrama( 0 );
}

char * Solicitud :: doOperation( char *IP, int puerto, int operationId, char *arguments ){
    
    struct mensaje datos,respuesa;
    char *aux;
    datos.messageType = 0;
    datos.operationId = operationId;
    datos.requestId = 1;
    memcpy( datos.arguments ,arguments , sizeof(arguments) );

    PaqueteDatagrama dat = PaqueteDatagrama( (char *)&datos, sizeof(datos), IP ,puerto );

    if( socketlocal->envia(dat) ){
        cout << "Enviando Mensaje:" << endl;
        cout << "IP: " << dat.obtieneDireccion() << endl;
        cout << "Puerto: " << dat.obtienePuerto() << endl;
        cout << "Longitud: " << dat.obtieneLongitud() << endl;
    }

    PaqueteDatagrama paqdata = PaqueteDatagrama( sizeof(respuesa) );

    if(socketlocal->recibe(paqdata)){
        memcpy(&respuesa, paqdata.obtieneDatos(), sizeof(respuesa) );
        cout << "\nRecibiendo Mensaje:" << endl;
        cout << "IP: " << paqdata.obtieneDireccion() << endl;
        cout << "Puerto: " << paqdata.obtienePuerto() << endl;
        printf("Respuesta: %d\n", respuesa.arguments[0]);
        cout << "Longitud: " << paqdata.obtieneLongitud() << endl;
    }
    aux = respuesa.arguments;
    return aux;
}