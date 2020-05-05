#include "Solicitud.h"
#include "registro.h"
#include <string.h>
#include <fstream>
#include <sys/time.h>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 4) {
		printf("Uso: %s IP del servidor Nombre_archivo n_registros\n", argv[0]);
		exit(1);
	}
	int i, j, n;
	int ptoServidor = 7300;
	char info[34];
	char cel[11],par[4],cu[19],reg[31];
	string ruta = argv[2];
	ifstream archivo( ruta, ios::in );
	struct registro reg1;
	struct timeval respuesta;
	n = atoi( argv[3] );
	Solicitud sol;

	if( archivo.fail() ){
		printf("Error al abrir el archivo\n");
		exit(1);
	}
	else{
		par[3]='\0';
		cel[10]='\0';
		cu[18]='\0';
		for(i = 0; i < n; i++){
			archivo.getline(info, sizeof(info));
			printf("Registro: %s\n", info);
			memcpy(&cel, &info, sizeof(cel)-1); //Celular 

			for(j = 0; j < 18; j++) //CURP
				cu[j] = info[ j + 10 ];

			for(j = 0; j < 3 ; j++)//Partido
				par[j] = info[ j + 28 ];

			memcpy(&reg1.celular, &cel, sizeof(cel));
			memcpy(&reg1.CURP, &cu, sizeof(cu));
			memcpy(&reg1.partido, &par, sizeof(par));

			printf("Cel: %s\n",reg1.celular);
			printf("CURP: %s\n",reg1.CURP);
			printf("Partido %s\n",reg1.partido);
			memcpy(&respuesta,sol.doOperation(argv[1],ptoServidor,0,(char*)&reg1), sizeof(respuesta) );
			printf("Segundos: %ld - microsegundos: %ld \n",respuesta.tv_sec,respuesta.tv_usec);
			printf("Enviado...\n\n");
		}
	}
	archivo.close();
}

