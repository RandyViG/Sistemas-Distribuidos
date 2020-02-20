#include <iostream>
#include"Rectangulo.h"
#include"Coordenada.h"

using namespace std;

int main(){
    Rectangulo rectangulo1(Coordenada(3.6056,0.9827),Coordenada(5.0990,0.1973));
    double operacion;
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
    rectangulo1.imprimeEsq();
    operacion=rectangulo1.obtieneArea();
    cout << "El área del rectángulo es = " << operacion << endl;
    return 0; 
}