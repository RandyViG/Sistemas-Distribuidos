/*
Compilar:
g++ -std=c++11  ejercicio7.cpp Semaforo.cpp -o semaforo -lpthread
*/

#include <iostream>
#include <unistd.h>
#include <thread>
#include "Semaforo.h"
#define n 10
using namespace std;

int global = 10;
Semaforo sem1, sem2,sem3;

void funcion1(){
    while(global > 0){
        sem1.wait();
        printf("Soy el hilo 1, y esta es la impresion %d\n", global--);
        sem2.post();
    }
}

void funcion2(){
    while(global > 0){
        sem2.wait();
        printf("Soy el hilo 2, y esta es la impresion %d\n", global--);
        sem3.post();
    }
}

void funcion3(){
    while(global > 0){
        sem3.wait();
        printf("Soy el hilo 3, y esta es la impresion %d\n", global--);
        sem1.post();
    }
}

int main(){
    //Inicializa los semaforossem1.init(1);
    sem1.init(1);
    sem2.init(0);
    sem3.init(0);
    thread th1(funcion1), th2(funcion2),th3(funcion3);
    th1.join();
    th2.join();
    th3.join();
    exit(0);
}