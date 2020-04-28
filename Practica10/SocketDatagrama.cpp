#include "SocketDatagrama.h"
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int p){
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(p);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){
    close(s);
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons( p.obtienePuerto() );
    return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    unsigned int len = sizeof(direccionForanea);
    int salida = recvfrom(s, (char*) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr*) &direccionForanea, &len);
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    return salida;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos){
    unsigned int len = sizeof(direccionForanea);
    timeout.tv_sec = segundos;
    timeout.tv_usec = microsegundos;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    int n;
    n = recvfrom(s, (char*) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr*) &direccionForanea, &len);
    if (n < 0){
        if (errno == EWOULDBLOCK){
            fprintf(stderr, "Tiempo para recepción transcurrido\n");
            return -1;
        }
        else
            fprintf(stderr, "Error en recvfrom\n");
    }
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    return n;
}

