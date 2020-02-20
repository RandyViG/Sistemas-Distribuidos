#include"Fecha.h"
#include<iostream>

int main(){
	Fecha a, b, c(21, 9 ,1973),d(1,4,2014);
	int total=0;
	b.inicializaFecha(17, 6, 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
	d.convierte();
	cout << " Es bisiesto :" << a.leapyr() << endl;

	Fecha e;
	for ( int i = 1; i < 2021 ; i++){
		e.inicializaFecha(1,1,i);
		if ( e.leapyr() )
			total++;
	}
	cout << "Total de años bisiestos : " << total << endl;

	return 0;
}