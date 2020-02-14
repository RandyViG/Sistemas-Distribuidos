#include<iostream>
#include"PoligonoIrregular.h"

using namespace std;

Poligonoirregular::Poligonoirregular(){}

Poligonoirregular::Poligonoirregular(double r){
    v.reserve(r);
}

void Poligonoirregular::AnadeVertice(Coordenada c){
    v.push_back(c);
    ves++;
    return;
}

void Poligonoirregular::MuestraVertice(){
    int i;
    for(i=0;i<=(v.size());i++){
        cout << "El vertice en x="<< v[i].obtenerX()<<"en Y"<< v[i].obtenerY()<<endl;
    }
    return;
}

int Poligonoirregular::veces(){
    return ves;
}