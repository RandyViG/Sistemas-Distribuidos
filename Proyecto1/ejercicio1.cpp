#include<iostream>

using namespace std;

int main( void ){
    double n,b,h;
    cout << " Raíz cuadrada utilizando al algoritmo babilónico " << endl;
    cout << "Ingresa el numero del cual quieres saber la raiz: ";
    cin >> n;
    b = n;
    h = 0;
    while ( h != b ){
        h=b;
        b = (n/b + h)/2;
    }
    cout << "La raiz cuadra de: " << n << " es: " << h << endl;
    return 0;
}
