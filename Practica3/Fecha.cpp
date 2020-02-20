#include"Fecha.h"
#include<iostream>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa): dia(dd), mes(mm), anio(aaaa){
	if((mes < 1) || (mes > 12)){
		cout << "Valor ilegal para el mes!\n";
		exit(1);
	}
	if ( (dia < 1) || (dia > 31) ){
		cout << "Valor ilegal para el dia!\n";
		exit(1);
	}
	if ( (anio < 0) || (anio > 2020) ){
		cout << "Valor ilegal para el año!\n";
		exit(1);
	}
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}

void Fecha::muestraFecha(){
	cout << "La fecha es(dia-mes-año): "<< dia << "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte(){
	int d;
    d=anio*10000+mes*100+dia;
    cout<<  "el valor devuelto es "<< d <<endl;
    return d;
}

bool Fecha::leapyr(){
	if ( anio%4 == 0 && anio%100 !=0 ){
		return true;
	}else{
		if ( anio % 400 == 0)
			return true;
		else
			return false;
	}
}