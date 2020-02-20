#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Fecha{
private:
	int dia;
	int mes;
	int anio;
	unsigned long long arr[10000];
public:
	Fecha(int = 3, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
	int convierte();
	bool leaypr();
};

Fecha::Fecha(int dd, int mm, int aaaa){
	mes = mm;
	dia = dd;
	anio = aaaa;
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
    //cout<<  "el valor devuelto es "<< d <<endl;
    return d;
}

bool Fecha::leaypr(){
	if(anio % 4 == 0 && anio % 100 != 0){
		return true;
	}
	else{
		if(anio % 400 == 0)
			return true;
		else
			return false;
	}
}

int masvieja(Fecha& fecha1, Fecha& fecha2){
	int f1,f2;
	f1 = fecha1.convierte();
	f2 = fecha2.convierte();
	if(f1 > f2)
		return 1;
	else if (f1 == f2)
		return 0;
	else if (f1 < f2)
		return -1;
}

int main()
{
	srand(time(0));
	//bool bi;
	Fecha a, b;
	cout << "Tamaño: " << sizeof(a);
	int c;
	for(int i=0;i<1000000;i++){
		a.inicializaFecha((long)1+(rand()%31), (long)1+(rand()%12), (long)1+(rand()%2020));
		b.inicializaFecha((long)1+(rand()%31), (long)1+(rand()%12), (long)1+(rand()%2020));
		c = masvieja(a,b);
		//cout << "Resultado: " << c << endl;

	}
	/*c.convierte();
	bi = c.leaypr();
	if(bi)
		cout << "Es bisiesto" << endl;
	else 
		cout << "No es bisiesto" << endl;*/
	return 0;
}