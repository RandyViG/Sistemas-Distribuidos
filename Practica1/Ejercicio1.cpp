#include<iostream>
using namespace std;
const double PI = 3.1415926;

int main(){
	double radio, area;

	cout << "!!!Hola!!!.\n" << "Bienvenidos a c++";
	cout << "\nIngresa el valor del radio: ";
	cin >>radio;
	area = PI*(radio*radio);
    cout << "\nEl area es: " << area;
    cout << "\nEl valor de PI es: \n" << PI ;
    
    /*No permite modificar el valor de una constante,
      ya que esta se declara como asignacion de 
      variable solo de lectura*/
    //PI = 4;

	return 0;
}
