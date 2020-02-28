#ifndef __RECTANGULO_H__
#define __RECTANGULO_H__
#include<iostream>
#include"Coordenada.h"

class Rectangulo{
    private:
        Coordenada superiorDer;
        Coordenada inferiorIzq;
    public:
        Rectangulo();
        Rectangulo(Coordenada cori, Coordenada cord);
        void inicializar(Coordenada cori, Coordenada cord);
        void imprimeEsq();
        Coordenada obtieneSupDer();
        Coordenada obtieneInfIzq();
        double obtieneArea();
};

#endif