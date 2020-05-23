#include "SocketDatagrama.h"
#include <stdio.h>
#include <iostream> 
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 3) {
		printf("Uso: %s IP del servidor Nombre_archivo\n", argv[0]);
		exit(1);
	}
	int i, j, n;
	int ptoServidor = 7300;
	char info[34];
	string ruta = argv[2];
	ifstream archivo(ruta, ios::in);
	SocketDatagrama s(0);

	if(archivo.fail()){
		printf("Error al abrir el archivo\n");
		exit(1);
	}
	else{
		archivo.getline(info, sizeof(info));
		info[31] = '\0';
		printf("Registro: %s\n",info);
		PaqueteDatagrama pe = PaqueteDatagrama(info, sizeof(info),argv[1],ptoServidor);
		s.envia(pe);
	}
	archivo.close();
}

