#include<iostream>
#include"Fraccion.h"

Fraccion :: Fraccion(int num , int den): numerador(num) , denominador(den){}

void Fraccion :: setFraccion(int num, int den){
    numerador = num;
    denominador = den;
}

double Fraccion :: getResult(){
    return (double)numerador / (double) denominador;
}

void Fraccion :: getMinimaExpresion(){
    int maxComunDivisor = mcd(numerador,denominador); 
    cout << "Minima expresión:";
    cout << numerador/maxComunDivisor << "/" << denominador/maxComunDivisor << endl;
}

int Fraccion :: mcd(int num, int den){
    if ( den == 0)
        return num;
    else
        return mcd( den, num%den );   
}