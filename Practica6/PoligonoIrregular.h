#ifndef __POLOGONOIRREGULAR_H__
#define __POLIOGNOIRREGULAR_H__

#include<iostream>
#include"Coordenada.h"
#include <vector>

using namespace std;

class Poligonoirregular{
    private:
        vector <Coordenada> v;
        static int ves;
    public:
     Poligonoirregular();
     Poligonoirregular(double);
     static int veces();
     void anadeVertice(Coordenada);
     void muestraVertice();
     void ordenar();
     
};

#endif