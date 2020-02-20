#include<iostream>
using namespace std;

int main(){
	int numeroDeLenguajes;

	cout << "!!!Hola!!!.\n" << "Bienvenidos a c++";
	cout << "\nCuantos lenguajes de programación dominas? ";
	cin >> numeroDeLenguajes;

	if (numeroDeLenguajes <1)
		cout << "Seria recomendable aprender antes un lenguaje más sencillo ... \n ejemplo C, auqnue nada es imposible. \n";
	else
		cout << "Este curso sera sencillo para ti\n";
	return 0;
}

