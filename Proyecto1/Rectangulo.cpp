#include<iostream>
#include"Rectangulo.h"
using namespace std;

Rectangulo::Rectangulo() : superiorDer(0,0,0), inferiorIzq(0,0,0)
{ }

Rectangulo::Rectangulo(Coordenada cd,Coordenada ci){ 
    inferiorIzq = cd;
    superiorDer = ci;
}

void Rectangulo::inicializar(Coordenada cd , Coordenada ci){
    inferiorIzq = cd;
    superiorDer = ci;
}

void Rectangulo::imprimeEsq(){
    cout << "Esquina inferior izquierda.\n";
    cout << "x = " << inferiorIzq.obtenerX() << " y = " << inferiorIzq.obtenerY() << " z = " << inferiorIzq.obtenerZ() << endl;
    cout << "Esquina superior derecha.\n";
    cout << "x = " << superiorDer.obtenerX() << " y = " << superiorDer.obtenerY() << " z = " << superiorDer.obtenerZ() << endl;
}

double Rectangulo::obtieneArea(){

    float alto = superiorDer.obtenerY() - inferiorIzq.obtenerY();
    float ancho = superiorDer.obtenerX() - inferiorIzq.obtenerX();
    return alto * ancho ;
}

Coordenada Rectangulo :: obtieneSupDer(){
    return superiorDer;
}

Coordenada Rectangulo :: obtieneInfIzq(){
    return inferiorIzq;
}