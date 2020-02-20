#ifndef __COORDENADA_H__
#define __COORDENADA_H__

#include<iostream>
using namespace std;

class Coordenada{
    private:
        double x;
        double y;
        double magnitud;  
    public:
        Coordenada(double = 0, double = 0);
        double obtenerX();
        double obtenerY();
        double obtenerMagnitud();
};

#endif