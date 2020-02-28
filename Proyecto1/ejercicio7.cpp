#include <iostream>
#include <vector>
#include <cmath>
#include "Criba.h"

using namespace std;

int main(){
    
    int n, inicial=2, multiplo;
    vector <Criba> primos;
    cout << "Ingresa el rango de numeros: ";
    cin >> n;
    primos.reserve(n);
    for (int i=0 ; i < n-1 ; i++){
        primos[i].setValor(inicial++);
        primos[i].setPrimo(true);
    }

    for (int i=2 ; i<n ; i+=2)
        primos[i].setPrimo(false);

    
    for (int i=1 ; i<n ; i++){
        if( primos[i].getPrimo() == false )
            continue;
        if( pow(primos[i].getValor() ,2) > n)
            break;

        multiplo = primos[i].getValor();

        for (int j=i+1 ; j<n ; j++){
            if( primos[j].getValor() % multiplo == 0)
                primos[j].setPrimo(false);
        }

    }

    cout << "Los numeros primos son: ";
    for(int i = 0 ; i<n ; i++)
        if( primos[i].getPrimo() )
            cout << primos[i].getValor() << ",";
    cout << endl;
    return 0;
}