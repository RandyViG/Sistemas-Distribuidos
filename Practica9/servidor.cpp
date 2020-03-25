#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int pto = 7200;
    SocketDatagrama server = SocketDatagrama( pto );
    cout << "Servidor iniciado" << endl;

    while(1) {
        PaqueteDatagrama mensaje = PaqueteDatagrama(2);

        if(server.recibe(mensaje)){
            char *dat = mensaje.obtieneDatos();
        	cout << "\nRemitente:" << endl;
        	cout << "IP: " << mensaje.obtieneDireccion() << endl;
        	cout << "Puerto: " << mensaje.obtienePuerto() << endl;
        	printf("Datos:  %d  %d\n", dat[0],dat[1]);
        	cout << "Longitud: " << mensaje.obtieneLongitud() << endl;

            printf("\nCreando Paquete");
            char res = dat[0] + dat[1];
            printf("\nsuma: %d",res);

            PaqueteDatagrama respuesta = PaqueteDatagrama( &res , 1 , mensaje.obtieneDireccion() , mensaje.obtienePuerto() );

            server.envia(respuesta);
            
            dat = respuesta.obtieneDatos();
            cout << "\nEnviado:" << endl;
        	cout << "IP: " << respuesta.obtieneDireccion() << endl;
        	cout << "Puerto: " << respuesta.obtienePuerto() << endl;
        	printf("Datos:  %d \n", dat[0]);
        	cout << "Longitud: " << respuesta.obtieneLongitud() << endl;

            printf("\nRespuesta Enviada");
        }
        fflush(stdin);
    }
}