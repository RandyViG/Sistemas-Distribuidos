#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;
char buffer[BUFSIZ];

int main(int argc, char *argv[]){
    int destino,r;
    char cadena[4], *cadenota = NULL;
    int n= 26*26*26*100, i;

    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
        exit(0);
    }

    cadena[3] = ' ';
    for(int i=0; i<n;i++){
        cadena[0] = rand()%25+65;
        cadena[1] = rand()%25+65;
        cadena[2] = rand()%25+65;
        cadenota = (char*)realloc(cadenota,4*(i+1));
        memcpy(cadenota+4*i, cadena, 4);
    }
    cadenota[4*n] = '\0'; 
    
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }
    for(i=0; i < n*4 ; i+=4 ){
        write(destino,&cadenota[i],4);
    }
    fsync(destino);
    close(destino);
}