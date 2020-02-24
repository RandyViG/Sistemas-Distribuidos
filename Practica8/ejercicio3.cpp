/*
Compilar: 
g++ -std=c++11  ejercicio3.cpp -o hilos1 -lpthread
*/
#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

int var = 0;

void incremento( int valor ){
    printf("Hilo: %ld , Incrementando\n", this_thread::get_id());
    for (int i = 0; i<valor; i++)
        var++;
    sleep(1);
}

void decremento( int valor ){
    printf("Hilo: %ld , Decremento\n", this_thread::get_id());
    for (int i = 0; i<valor; i++)
        var--;
    sleep(1);
}

int main(){
    thread th1(incremento,10000), th2(decremento,10000);
    cout  << "Proceso principal espera que los hilos terminen\n";
    th1.join();
    th2.join();
    cout << "Valor global: " << var << endl;
    cout << "El hilo principal termina\n";
    exit(0);
}