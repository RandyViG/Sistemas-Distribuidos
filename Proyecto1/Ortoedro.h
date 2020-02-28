#ifndef __ORTOEDRO_H__
#define __ORTOEDRO_H__

#include<iostream>
#include"Rectangulo.h"
#include"Coordenada.h"

using namespace std;

class Ortoedro{
    private:
        Rectangulo rec;
        Rectangulo rectangulo[6];
        Coordenada esqOrigen;
        Coordenada esqOpuesto;
    public:
        Ortoedro();
        Ortoedro( Coordenada origen , Coordenada opuesto );
        void obtieneVertices();
        void obtieneArea();
        void obtieneVolumen();
};

#endif