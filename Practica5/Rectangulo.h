#ifndef __RECTANGULO_H__
#define __RECTANGULO_H__
#include<iostream>
#include"Coordenada.h"

class Rectangulo{
    private:
        Coordenada superiorIzq;
        Coordenada inferiorDer;
    public:
        Rectangulo();
        Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
        void imprimeEsq();
        Coordenada obtieneSupIzq();
        Coordenada obtieneInfDer();
};

#endif