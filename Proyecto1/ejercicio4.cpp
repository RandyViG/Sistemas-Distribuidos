#include<iostream>
#include"Temperatura.h"

using namespace std;
void ingresarTemperatura( Temperatura t );
void mostrarDatos( Temperatura t );

int main( ){
    Temperatura t;
    t.setTempCelsius(21);
    t.getTempCelsius();
    t.getTempFahrenheit();
    t.getTempKelvin();

    t.setTempFahrenheit(86);
    t.getTempCelsius();
    t.getTempFahrenheit();
    t.getTempKelvin();

    t.setTempKelvin(323.15);
    t.getTempCelsius();
    t.getTempFahrenheit();
    t.getTempKelvin();

    return 0;
}
