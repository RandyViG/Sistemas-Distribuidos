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
    pol.reserve(100000);
    double r = 0;
    for(int i = 0; i < 100000; i++){
        r = rand() % 1000; 
        Poligonoirregular pi(r);
        for(int j = 0; j < r; j++){
            Coordenada c(r,r);
            pi.AnadeVertice(c);
        }
        pol[i] = pi;
        cont = cont + pi.veces();
    }
    cout << "Veces: " << cont << endl;
    return 0; 
}
