#include <iostream>
#include "Criba.h"

using namespace std;

bool Criba :: getPrimo(){
    return isPrimo;
}

void Criba :: setPrimo( bool prim){
    isPrimo = prim;
}

int Criba :: getValor(){
    return valor;
}

void Criba :: setValor( int val){
    valor = val;
}