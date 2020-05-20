#include "Solicitud.h"
#include <string.h>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3) {
		printf("Uso: %s IP del servidor n\n", argv[0]);
		exit(1);
	}
	int num, resultado, pesos, cuenta = 0;
    int ptoServidor = 7300;
    num = atoi(argv[2]);
    Solicitud sol;
    srand(time(NULL));
    for (int i = 0; i < num ; i++){
        pesos = 1 + rand()%9 ;
        cuenta += pesos;
        memcpy(&resultado,sol.doOperation( argv[1] , ptoServidor , 1 ,(char*)&pesos ),4);
        if( cuenta !=  resultado ){
            printf("\nError las cuentas no coinciden\n");
            printf("\nCuenta local: %d, cuenta en linea: %d\n",cuenta,resultado);
            break;
        }
    }
    return 0;
}