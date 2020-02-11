#include"Coordenada.h"
#include<iostream>
#include <cmath>
#define PI 3.141592653589793

using namespace std;

Coordenada::Coordenada(double r, double teta) {
    x = r * cos(teta);
    y = r * sin(teta);
 }

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}