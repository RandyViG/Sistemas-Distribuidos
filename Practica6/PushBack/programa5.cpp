#include <iostream>
#include <cstdlib>
#include <ctime>
#include"PoligonoIrregular.h"

using namespace std;

int Poligonoirregular::ves = 0;

int main(){
    srand(time(0));
    int cont = 0; 
    vector<Poligonoirregular> pol;
    double r = 0;
    for(int i = 0; i < 100000; i++){
        r = rand() % 1000; 
        Poligonoirregular pi;
        for(int j = 0; j < r; j++){
            Coordenada c(r,r);
            pi.AnadeVertice(c);
        }
        pol.push_back(pi);
        cont = cont + pol[i].veces();
    }
    cout << "Veces: " << cont << endl;
    //p.MuestraVertice();
    return 0; 
}

