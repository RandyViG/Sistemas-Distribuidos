//Programa para crear registros de votos [celular, CURP, partido, separador], con el campo "celular" como clave 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <iterator> 
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand

using namespace std; 

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
	string toString(){
		return string(celular)+string(CURP)+string(partido)+"\n";
	}
};

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Forma de uso: programa numero_registros nombre_archivo\n");
		exit(0);
	}
	char telefono[11], curp[19], sexo;
	int i, n, destino, j, opcion, inicial, elemento;;
	struct registro reg1;
    vector<struct registro> registros_vector; 

	//Partidos disponibles 2018
	char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE", "MVC", "MOR", "PES", "PNL"};

	//Entidades federativas
	char const entidad[32][3] =  {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};

	reg1.celular[10]='\0';
	reg1.CURP[17]='\0';
	reg1.partido[3]='\0';

	//Numero de registros n
	n = atoi(argv[1]);
	
	if( (destino = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1 ){
        perror(argv[2]);
        exit(-1);
    }
    
	//Genera un numeros telefonicos inicial de 9 digitos y despues se obtendran su secuenciales para evitar repeticion
	inicial = 500000000 + rand()%100000000;

	//Crea todos los registros con numero de telefono consecutivo y los almacena en un vector
	for(j=0; j<n; j++){
		sprintf(telefono, "5%9d", inicial);
		inicial++;
		strcpy(reg1.celular, telefono);

		if(rand()%2 == 0)
			sexo = 77;
		else
			sexo = 72;

		i = rand()%32;
		sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c%c", 65 + rand()%25 , 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, 
			sexo, entidad[i], 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48);
		strcpy(reg1.CURP, curp);

		i = rand()%9;
		strcpy(reg1.partido, partidos[i]);
		registros_vector.push_back(reg1);
	}

	//Aleatoriza el vector de registros e imprime el resultado
	random_shuffle(registros_vector.begin(), registros_vector.end());
	string aux;
	for (std::vector<struct registro>::iterator it=registros_vector.begin(); it!=registros_vector.end(); ++it){
		reg1 = *it;
		write(destino, reg1.toString().c_str() , sizeof( reg1.toString() ) );
	}
	fsync(destino);
	close(destino);
}
