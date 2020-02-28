#include<iostream>
#include"Ortoedro.h"
#include"Rectangulo.h"
#include"Coordenada.h"

using namespace std;

Ortoedro :: Ortoedro (): esqOrigen(0,0,0),esqOpuesto(0,0,0) {}

Ortoedro :: Ortoedro( Coordenada origen , Coordenada opuesto ){
    esqOrigen = origen;
    esqOpuesto = opuesto;

    Coordenada aux;

    aux.inicializar( opuesto.obtenerX() , origen.obtenerY(), opuesto.obtenerZ() );
    rectangulo[0].inicializar(origen, aux);

    aux.inicializar( origen.obtenerX() , opuesto.obtenerY(), opuesto.obtenerZ() );
    rectangulo[1].inicializar(origen, aux);

    aux.inicializar( origen.obtenerX() , opuesto.obtenerY(), origen.obtenerZ() );
    rectangulo[2].inicializar(aux, opuesto);

    aux.inicializar( opuesto.obtenerX() , origen.obtenerY(), origen.obtenerZ() );
    rectangulo[3].inicializar(aux, opuesto);

    aux.inicializar( opuesto.obtenerX() , opuesto.obtenerY(), origen.obtenerZ() );
    rectangulo[4].inicializar(origen, aux);

    aux.inicializar( origen.obtenerX() , origen.obtenerY(), opuesto.obtenerZ() );
    rectangulo[5].inicializar(aux, opuesto);
}

void Ortoedro :: obtieneArea(){
    double superficie = rectangulo[5].obtieneArea();
    cout << "\nLa superficie del ortoedro es: " << superficie << endl;
}

void Ortoedro :: obtieneVertices(){
    for (int i = 0; i< 6; i++){
        cout << "\nRectangulo " << i+1 << endl;
        rectangulo[i].imprimeEsq();
    }
}

void Ortoedro :: obtieneVolumen(){
    double superficie = rectangulo[5].obtieneArea();
    cout << "El volumen es: " << superficie * esqOpuesto.obtenerZ() << endl;
}