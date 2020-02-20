#include<stdio.h>
#include<stdlib.h>

int main(){
	char caracter = 0 , *pCaracter , cadena[]= "ESCOM - IPN";
	int entero = 0 , *pEntero , var = 1234567890 , i;
	float flotante = 0 , *pFlotante;
	long largo = 0 , *pLargo;
	double doble = 0, *pDoble;

	printf("caracter -> dir: %p tam: %d \n",&caracter, sizeof(caracter) );
	printf("entero   -> dir: %p tam: %d \n",&entero, sizeof(entero) );
	printf("flotante -> dir: %p tam: %d \n",&flotante, sizeof(flotante) );
	printf("largo    -> dir: %p tam: %d \n",&largo, sizeof(largo) );
	printf("double   -> dir: %p tam: %d \n",&doble, sizeof(doble));
	printf("apuntador: %d\n", sizeof(pCaracter) );
	
	pCaracter = (char *) malloc( sizeof(char) );
	pEntero = (int *) malloc( sizeof(int) );
	pFlotante = (float *) malloc( sizeof(float) );
	pLargo = (long *) malloc( sizeof(long) );
	pDoble = (double *) malloc( sizeof(double) );

	printf("apuntador char: %c\n", *pCaracter );
	printf("apuntador int: %d \n", *pEntero );
	printf("apuntador float: %f \n", *pFlotante );
	printf("apuntador largo: %ld \n", *pLargo );
	printf("apuntador doble: %d \n", *pDoble );
	
	for (i=0; i < 11 ; i++)
		printf("Letra: %c  ascii: %d  dir:%p \n", cadena[i],cadena[i],cadena[i]);
	printf("Cadena + 4: %c\n", *(cadena+4));

	printf("Positivo %d y %x\n", var, var);
	printf("Negativo %d y %x\n", -var, -var);
	return 0;
}
