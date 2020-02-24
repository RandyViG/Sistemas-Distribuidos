/*
Compilar: 
g++ -std=c++11  ejercicio6.cpp -o hilos1 -lpthread
*/
#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;

int var = 0;
mutex m;

void incremento( int valor ){
    for (int i = 0; i<valor; i++){
        m.lock();
        printf("\tHilo: %ld , Incrementando\n", this_thread::get_id());
        var++;
        m.unlock();
    }
}

void decremento( int valor ){
    for (int i = 0; i<valor; i++){
        m.lock();
        printf("Hilo: %ld , Decremento\n", this_thread::get_id());
        var--;
        m.unlock();
    }
}

int main(){
    thread th1(incremento,100000), th2(decremento,100000);
    cout  << "Proceso principal espera que los hilos terminen\n";
    th1.join();
    th2.join();
    cout << "Valor global: " << var << endl;
    cout << "El hilo principal termina\n";
    exit(0);
}