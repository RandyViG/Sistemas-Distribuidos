#include <iostream>
#include <thread>

using namespace std;

#define numeroElementos 100000000

void ram(){
    int *arreglo, i;
    arreglo = new int[numeroElementos];
    for(i = 0; i < numeroElementos; i++)
        arreglo[i] = 0;
    for(i = 0; i < 990000000; i++){
        arreglo[rand()%numeroElementos] = rand();
    }  
}

int main(){
    thread th1(ram), th2(ram);
    cout  << "Proceso principal espera que los hilos terminen\n";
    th1.join();
    th2.join();cout << "El hilo principal termina\n";
    exit(0);
}