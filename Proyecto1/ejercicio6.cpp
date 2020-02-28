#include<iostream>
#include"Ortoedro.h"

using namespace std;

int main(){
    Ortoedro o(Coordenada(0,0,0),Coordenada(5,4,3));
    o.obtieneVertices();
    o.obtieneArea();
    o.obtieneVolumen();
    
}