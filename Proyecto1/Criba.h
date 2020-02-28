#ifndef __CRIBA_H__
#define __CRIBA_H__

#include <iostream>

using namespace std;

class Criba{
    private:
        int valor;
        bool isPrimo;
    public:
        void setValor( int );
        int getValor();
        bool getPrimo();
        void setPrimo( bool );
};

#endif