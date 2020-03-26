#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 5) {
		printf("Uso: %s IP del servidor Val1 Val2 intentos\n", argv[0]);
		exit(1);
	}
	char num[2] , *resultado;
    int ptoServidor = 7300;
    num[0] = atoi(argv[2]);
    num[1] = atoi(argv[3]);
    Solicitud sol;
    for (int i = 0; i < atoi(argv[4]) ; i++){
        resultado = sol.doOperation( argv[1] , ptoServidor , 1 , num );
        printf("\nRespuesta: %d\n",resultado[0]);
    }
    
    return 0;
}