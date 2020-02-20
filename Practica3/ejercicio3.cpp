#include<unistd.h>
#include<iostream>

using namespace std;

class NumerosRand{
    private:
        int * arreglo;
        unsigned int numerosElementos;
    public:
        NumerosRand(unsigned int num);
        ~NumerosRand();
        void iniciliazarNumerosRand(void);
};

NumerosRand :: NumerosRand(unsigned int num){
    numerosElementos = num;
    arreglo = new int[numerosElementos];
}

NumerosRand :: ~NumerosRand(){
    delete[] arreglo;
}

void NumerosRand::iniciliazarNumerosRand(){
    unsigned int i;
    for ( i = 0; i < numerosElementos;i++)
        arreglo[i] = rand();
    return;
}

void pruebaClase(){
    unsigned int capacidad;
    cout << "Numero de enteros aleatorios en el arreglo: ";
    cin >> capacidad;
    NumerosRand tmp(capacidad);
    tmp.iniciliazarNumerosRand();
    sleep(7);
}

int main(){
    char res;
    do{
        pruebaClase();

        cout << "Probar de nuevo? (S/n)";
        cin >> res;
    }while( (res=='s') || (res=='S') );
}