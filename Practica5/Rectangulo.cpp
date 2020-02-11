#include<iostream>
#include"Rectangulo.h"
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0)
{ }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
{ }

Rectangulo::Rectangulo(Coordenada ci, Coordenada cd):superiorIzq(0,0), inferiorDer(0,0){ 
    superiorIzq = ci;
    inferiorDer = cd;
}

void Rectangulo::imprimeEsq(){
    cout << "Para la esquina superior izquierda.\n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina inferior derecha.\n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

double Rectangulo::obtieneArea(){

    float alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
    float ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();
    cout<<"Area del rectangulo es: " << alto << " " << ancho <<endl;
    return ( (superiorIzq.obtenerY() - inferiorDer.obtenerY())*(inferiorDer.obtenerX() - superiorIzq.obtenerX()) );
}

Coordenada Rectangulo :: obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo :: obtieneInfDer(){
    return inferiorDer;
}