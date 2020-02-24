#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

int var = 0;

void incremento(){
    printf("Hilo: %ld , Incrementando\n", this_thread::get_id());
    sleep(1);
}

void decremento(){
    printf("Hilo: %ld , Decremento\n", this_thread::get_id());
    sleep(1);
}

int main(){
    thread th1(incremento), th2(decremento);
    cout  << "Proceso principal espera que los hilos terminen\n";
    th1.join();
    th2.join();
    cout << "Valor global: " << var << endl;
    cout << "El hilo principal termina\n";
    exit(0);
}