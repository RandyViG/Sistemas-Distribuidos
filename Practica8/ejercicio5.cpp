#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>

using namespace std;

//atomic<int> var(0);
//int var = 0;

void incremento(int n, atomic<int> &var){
    printf("Hilo: %ld , Incrementando\n", this_thread::get_id());
    for(int i = 0; i<n ; i++)
        var++;
    sleep(1);
}

void decremento(int n, atomic<int> &var){
    printf("Hilo: %ld , Decremento\n", this_thread::get_id());
    for(int i = 0; i<n ; i++)
        var--;
    sleep(1);
}

int main(){
    atomic<int> var(0);
    thread th1(incremento,100000,ref(var)), th2(decremento,100000,ref(var));
    cout  << "Proceso principal espera que los hilos terminen\n";
    th1.join();
    th2.join();
    cout << "Valor global: " << var << endl;
    cout << "El hilo principal termina\n";
    exit(0);
}