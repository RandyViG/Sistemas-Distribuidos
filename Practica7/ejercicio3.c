#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main( void ){
    char *cadena, *cadenota=NULL,*c;
    int pos = 4,i,j,n,cantidad=0;
    cadena = (char *) malloc(4);
    c = (char *)malloc(1);
    srand(time(NULL));
    n = rand() % 100;

    for (i=0; i < 87000000 ;i++){
        for( j=0 ; j < 3 ; j++ ){
            c[0] = 65 + rand() % 25;
            strcat(cadena,c);
        }
        strcat(cadena," ");
        pos += 4;
        cadenota = (char *) realloc(cadenota,pos);
        strncat(cadenota,cadena,4);
        strcpy(cadena,"");
    }

    for (i=0; i < 87000000*4 ; i+=4){
        if (cadenota[i] == 'I' && cadenota[i+1]=='P' && cadenota[i+2]=='N' )
            cantidad++;
        printf("%c", cadenota[i]);
    }
    //printf("\nPañabras generadas: %d",n*1000);
    printf("\nCantidad: %d\n",cantidad);
}