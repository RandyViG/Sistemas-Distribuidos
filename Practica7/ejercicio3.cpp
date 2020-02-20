#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime>
using namespace std;

int r,f ;


int main() {
	srand(time(0));
	//f=1000*((26)^3);
	int cont=0;
	string cadena1(""),cadena2("");
	for(int j=0;j<87000000;j++){
		for(int i=0; i<3; i++) {
			r=65 + rand() % 25;
			cadena1+=r;
		}
		cadena1=cadena1+" ";
	cadena2+=cadena1;	
	}
	
	for (int i=0; i < 87000000;i+=4){
		if (cadena2[i]=='I' && cadena2[i+1]=='P' && cadena2[i+2]=='N')
			cont++;
	}
	cout << "Ocurrencias: " << cont;
	return 0;
}
