#include "Solicitud.h"
#include "registro.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include <sys/time.h>

using namespace std;

struct servidor{
	char *ip;
	char *nomArchivo;
	int pto;
	int nRegistros;
	char limInferior;
	char limSuperrior;
};

void enviarRegistro( struct servidor * datos );

int main(int argc, char *argv[]){
	if(argc != 9) {
		printf("Uso: %s IP_SA PTO_SA IP_SB PTO_SB IP_SC PTO_SC Nombre_archivo n_registros\n", argv[0]);
		exit(1);
	}
	int i = 0;
	struct servidor datos[3];
	for( i = 1; i <= 3 ; i++){
		datos[i-1].nomArchivo = argv[7];
		datos[i-1].nRegistros = atoi( argv[8] );
		datos[i-1].pto = atoi( argv[2*i] );
	}
	int j;
	for( i = 1 , j=0; i <=5 ; i+=2 , j++)
		datos[j].ip = argv[i];

	datos[0].limInferior='0'; datos[0].limSuperrior='3';
	datos[1].limInferior='4'; datos[1].limSuperrior='6';
	datos[2].limInferior='7'; datos[2].limSuperrior='9';

	for( i = 0; i < 3 ; i++){
		printf("IP: %s\n",datos[i].ip);
		printf("Pto: %d\n",datos[i].pto);
		printf("Inf %c Sup %c\n\n",datos[i].limInferior,datos[i].limSuperrior);
	}

	thread th1(enviarRegistro,&datos[0]),
	       th2(enviarRegistro,&datos[1]),
		   th3(enviarRegistro,&datos[2]);
	th1.join(); th2.join(); th3.join();
	return 0;
}

void enviarRegistro( struct servidor * datos ){
	char cel[11],par[4],cu[19],reg[31],info[33];
	int archivo,i,j;
	Solicitud sol;
	struct timeval respuesta;
	struct registro reg1;

	if( ( archivo = open(datos->nomArchivo, O_RDONLY,0666) ) == -1 )
        perror(datos->nomArchivo);
	else{
		par[3]='\0';
		cel[10]='\0';
		cu[18]='\0';	
		info[32]='\0';
		for(i = 0; i < datos->nRegistros; i++){
			read( archivo , info , 32 );
			memcpy(&cel, &info, sizeof(cel)-1); //Celular 
			for(j = 0; j < 18; j++) //CURP
				cu[j] = info[ j + 10 ];
			for(j = 0; j < 3 ; j++)//Partido
				par[j] = info[ j + 28 ];
			memcpy(&reg1.celular, &cel, sizeof(cel));
			memcpy(&reg1.CURP, &cu, sizeof(cu));
			memcpy(&reg1.partido, &par, sizeof(par));
			if( reg1.celular[9] >= datos->limInferior && reg1.celular[9] <= datos->limSuperrior )
				memcpy(&respuesta,sol.doOperation(datos->ip,datos->pto,0,(char*)&reg1), sizeof(respuesta) );
		}
		close( archivo );
	}
}