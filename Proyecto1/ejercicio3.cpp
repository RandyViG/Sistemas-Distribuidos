#include<iostream>
using namespace std;

int main(void){
    int horas,minutos,segundos;
    cout << "Ingresa el tiempo en segundos: " ;
    cin >> segundos;
    minutos = segundos / 60;
    segundos = segundos % 60;
    horas = minutos / 60;
    minutos = minutos % 60;
    cout << "Equivale a " << horas << " horas con " << minutos << " minutos y " <<
        segundos << " segundos" << endl; 
}