#ifndef __TEMPERATURA_H__
#define __TEMPARATURA_H__

#include<iostream>
using namespace std;

class Temperatura{
    private:
        double kelvin;
    public:
        Temperatura( double = 0.0 );
        void setTempKelvin( double temp);
        void setTempFahrenheit( double temp );
        void setTempCelsius( double temp );
        void getTempKelvin( );
        void getTempFahrenheit( );
        void getTempCelsius( );
};

#endif
