#include <iostream>
#include <cstring>
#include "Solicitud.h"
#include "mensaje.h"

#define SEGUNDOS 2
#define MICROSEGUNDOS 500000
using namespace std;

Solicitud :: Solicitud (){
    socketlocal = new SocketDatagrama( 0 );
}

char * Solicitud :: doOperation( char *IP, int puerto, int operationId, char *arguments , int intentos){
    
    struct mensaje datos,respuesa;
    char *aux;
    int i,n;
    datos.messageType = 0;
    datos.operationId = operationId;
    datos.requestId = 1;
    memcpy( datos.arguments ,arguments , sizeof(arguments) );

    PaqueteDatagrama dat = PaqueteDatagrama( (char *)&datos, sizeof(datos), IP ,puerto );
    PaqueteDatagrama paqdata = PaqueteDatagrama( sizeof(respuesa) );

    for(i=0; i < intentos ; i++){
        if( socketlocal->envia(dat) ){
            cout << "\nEnviando Mensaje:" << endl;
            cout << "IP: " << dat.obtieneDireccion() << endl;
            cout << "Puerto: " << dat.obtienePuerto() << endl;
            cout << "Longitud: " << dat.obtieneLongitud() << endl;
        }

        n = socketlocal->recibeTimeout(paqdata,SEGUNDOS,MICROSEGUNDOS);
        if ( n != -1){
            memcpy(&respuesa, paqdata.obtieneDatos(), sizeof(respuesa) );
            cout << "\nRecibiendo Mensaje:" << endl;
            cout << "IP: " << paqdata.obtieneDireccion() << endl;
            cout << "Puerto: " << paqdata.obtienePuerto() << endl;
            printf("Respuesta: %d\n", respuesa.arguments[0]);
            cout << "Longitud: " << paqdata.obtieneLongitud() << endl;
            aux = respuesa.arguments;
            return aux;
        }
    }
    printf("\n *** Servidor No Disponible, Intente Mas Tarde ***\n");
    exit(-1);
}