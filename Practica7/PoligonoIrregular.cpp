#include<iostream>
#include<vector>
#include <algorithm>
#include"PoligonoIrregular.h"

using namespace std;

using namespace std;
struct myclass {
  bool operator() (Coordenada i, Coordenada j) { return (i.obtenerMagnitud()<j.obtenerMagnitud());}
} myobject;

Poligonoirregular::Poligonoirregular(){}

Poligonoirregular::Poligonoirregular(double r){
    v.reserve(r);
}

void Poligonoirregular::anadeVertice(Coordenada c){
    v.push_back(c);
    ves++;
}

void Poligonoirregular::muestraVertice(){

    cout << "Coordenadas: " << endl;
    vector< Coordenada >::iterator ir;
    for (ir = v.begin( ); ir != v.end( ); ir++){
        cout << "Coordenadas: " << "x: " << ir->obtenerX() << " y: " << ir->obtenerY();
        cout << "  Magnitud: " << ir->obtenerMagnitud() << endl;
    }
}

int Poligonoirregular::veces(){
    return ves;
}

void Poligonoirregular::ordenar(){
    sort( v.begin(),v.end() , myobject);
}