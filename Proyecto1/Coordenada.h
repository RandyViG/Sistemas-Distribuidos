#ifndef __COORDENADA_H__
#define __COORDENADA_H__

class Coordenada{
    private:
        double x;
        double y;
        double z;  
    public:
        Coordenada();
        Coordenada(double xx, double yy, double zz);
        void inicializar(double xx, double yy, double zz);
        double obtenerX();
        double obtenerY();
        double obtenerZ();
};

#endif
