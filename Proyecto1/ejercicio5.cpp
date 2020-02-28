#include<iostream>
#include"Fraccion.h"

using namespace std;

int main(){
    Fraccion f;
    double result;
    f.setFraccion(18,15);
    cout << "Resultado es: " << f.getResult() << endl;
    f.getMinimaExpresion();

    return 0;
}