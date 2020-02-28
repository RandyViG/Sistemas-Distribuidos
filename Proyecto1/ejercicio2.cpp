/**/
#include<iostream>
using namespace std;
const float GRAVEDAD = 9.80665;

int main( void ){
    float tiempo,altura;
    cout << "Ingresa el tiempo que tarde en caer la pelota: ";
    cin >> tiempo;
    altura = ( GRAVEDAD*(tiempo*tiempo) )/2;
    cout << "La altura del edificio es: " << altura << endl;
}