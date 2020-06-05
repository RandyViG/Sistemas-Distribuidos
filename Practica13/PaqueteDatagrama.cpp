#include "PaqueteDatagrama.h"
#include <iostream>
#include <string.h>

using namespace std;
PaqueteDatagrama::PaqueteDatagrama(char *d, unsigned int t, char *i, int p){
    datos= new char[t];
    memcpy(datos, d, t);
    //printf("datos %s",datos);
    longitud=t;
    memcpy(ip, i, 16);
    puerto=p;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int t){
    datos= new char[t];
    longitud=t;

}
PaqueteDatagrama::~PaqueteDatagrama(){
    delete[] datos;
    longitud = 0;
    puerto = 0;
}

char * PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char * PaqueteDatagrama::obtieneDatos(){
    return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
    puerto=p;
}

void PaqueteDatagrama::inicializaIp(char * i){
    memcpy(ip, i, 16);
}

void PaqueteDatagrama::inicializaDatos(char * d){
    memcpy(datos,d,longitud);
}