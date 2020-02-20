
#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
   
  char cadena[4], *cadenota = NULL;
  int n= 26*26*26*5000, coincidencias = 0, i;

  cadena[3] = ' ';
  for(int i=0; i<n;i++){
    cadena[0] = rand()%25+65;
    cadena[1] = rand()%25+65;
    cadena[2] = rand()%25+65;
    cadenota = (char*)realloc(cadenota,4*(i+1));
    memcpy(cadenota+4*i, cadena, 4);
  }
  cadenota[4*n] = '\0';
  
  for(i=0; i<n*4; i+=4){
    if(cadenota[i] == 'I' && cadenota[i+1] == 'P' && cadenota[i+2] == 'N'){
      coincidencias++;
    }
  }  
  printf("Se encontraron: %d coincidencias\n", coincidencias); 
  free(cadenota);
}
