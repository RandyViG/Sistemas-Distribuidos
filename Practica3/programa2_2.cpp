#include"Fecha.h"
#include<iostream>

int main(){
	Fecha a, b, c(21, 9 ,1973),d(1,4,2014);
	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
	d.convierte();
	return 0;
}