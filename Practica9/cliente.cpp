#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2) {
		printf("Uso: %s IP del servidor\n", argv[0]);
		exit(0);
	}
	char num[2] = { 2 , 5 };
    int ptoCliente = 6666 , ptoServidor = 7200;

    SocketDatagrama client = SocketDatagrama( ptoCliente );
    PaqueteDatagrama dat = PaqueteDatagrama( num, 2, argv[1], ptoServidor );
    if(client.envia(dat)){
        cout << "Detinatario:" << endl;
        cout << "IP: " << dat.obtieneDireccion() << endl;
        cout << "Puerto: " << dat.obtienePuerto() << endl;
        cout << "Longitud: " << dat.obtieneLongitud() << endl;
    }

    PaqueteDatagrama paqdata = PaqueteDatagrama(1);
    if(client.recibe(paqdata)){
        cout << "\nMensaje recibido de:" << endl;
        cout << "IP: " << paqdata.obtieneDireccion() << endl;
        cout << "Puerto: " << paqdata.obtienePuerto() << endl;
        int res2;
		memcpy(&res2, paqdata.obtieneDatos(), 1);
        printf("Respuesta: %d\n", res2);
        cout << "Longitud: " << paqdata.obtieneLongitud() << endl;
    }
    return 0;
}