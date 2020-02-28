#ifndef __FRACCION_H__
#define __FRACCION_H__

#include<iostream>
using namespace std;

class Fraccion{
    private:
        int numerador;
        int denominador;
    public:
        Fraccion(int = 0, int = 0);
        void setFraccion(int num, int den);
        double getResult();
        void getMinimaExpresion();
        int mcd(int num, int den);
};

#endif