#ifndef FECHA_H_
#define FECHA_H_

#include <iostream>
using namespace std;

class Fecha{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int = 3, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
	int convierte();
	bool leapyr();
};

#endif