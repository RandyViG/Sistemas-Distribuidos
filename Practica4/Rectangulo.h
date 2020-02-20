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
        Rectangulo(Coordenada cori, Coordenada cord);
        void imprimeEsq();
        Coordenada obtieneSupIzq();
        Coordenada obtieneInfDer();
        double obtieneArea();
};

#endif