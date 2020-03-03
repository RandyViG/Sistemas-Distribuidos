#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cmath>
#include <thread>

using namespace std;
char buffer[BUFSIZ];

void writeFile( char *name ){
    int destino,r;
    char cadena[4], *cadenota = NULL;
    int n= 26*26*26*100, i;

    cadena[3] = ' ';
    for(int i=0; i<n;i++){
        cadena[0] = rand()%25+65;
        cadena[1] = rand()%25+65;
        cadena[2] = rand()%25+65;
        cadenota = (char*)realloc(cadenota,4*(i+1));
        memcpy(cadenota+4*i, cadena, 4);
    }
    cadenota[4*n] = '\0'; 
    
    if((destino = open(name, O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(name);
        exit(-1);
    }
    for(i=0; i < n*4 ; i++ ){
        write(destino,&cadenota[i],1);
    }
    fsync(destino);
    close(destino);
}

void CPU(int max){
    double i = 0.0;
    double seno1 = 0.0;
    double cos1 = 0.0;
    double tan1 = 0.0;
    double log1 = 0.0;
    double raizc = 0.0;
    while(i < max) {
        seno1 += sin(i);
        cos1 += cos(i);
        tan1 += tan(i);
        log1 += log(i);
        raizc += sqrt(i);
        i += 1;
    }
}

int main( ){
    double max = 26.0*26.0*26.0*10500.0;
    char *name1 = {"DDvCPU.txt"}; //*name2 = {"Hilo2.txt"};
    thread th1(writeFile,name1), th2(CPU,max);
    cout  << "Proceso principal espera que los hilos terminen\n";
    th1.join();
    th2.join();cout << "El hilo principal termina\n";
    
    exit(0); 
}