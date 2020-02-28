#include"Temperatura.h"
#include<iostream>

using namespace std;

Temperatura :: Temperatura( double temp ): kelvin(temp) { }

void Temperatura :: setTempKelvin( double temp){ 
    kelvin = temp;
}
void Temperatura :: setTempFahrenheit( double temp ){
    kelvin = (temp - 32 ) * 5.0/9.0 + 273.15;
}
void Temperatura :: setTempCelsius( double temp ){
    kelvin = temp + 273.15;
}
void Temperatura :: getTempKelvin( ){
    cout << "La tempperatura en kelvin es: " << kelvin << endl;
}
void Temperatura :: getTempFahrenheit( ){
    cout << "La temperatura en Fahrenheit es: "<< (kelvin - 273.15)* 9.0/5.0 + 32 << endl; 
}
void Temperatura :: getTempCelsius( ){
    cout << "La temperatura en Celsius es: " << (kelvin - 273.15) << endl;
}   