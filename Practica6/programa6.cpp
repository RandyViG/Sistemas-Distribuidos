#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include"PoligonoIrregular.h"
#include"Coordenada.h"

using namespace std;

int Poligonoirregular::ves = 0;

int main(){
    cout << "Inicializando valores: " <<endl;
    srand(time(0));
    int n = -100 + (rand() % 100);
    Poligonoirregular p;
    for (int i = 0; i < 10 ; i++){
        double x = (rand() % (200000)-100000) / 1000.0;
        double y = (rand() % (200000)-100000) / 1000.0; 
        p.anadeVertice(Coordenada(x,y));
    }
    p.muestraVertice();
    p.ordenar();
    p.muestraVertice();
    return 0; 
}
