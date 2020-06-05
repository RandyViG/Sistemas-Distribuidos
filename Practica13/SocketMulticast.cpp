#include "SocketMulticast.h"
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

SocketMulticast :: SocketMulticast(int p){
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s < 0) {
        perror("Error en la creación del socket");
        exit(1);
    }
    int reuse = 1;
    if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
        printf("Error al llamar a la función setsockopt\n");
        exit(0);
    }
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(p);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}
SocketMulticast :: ~SocketMulticast(){
    close(s);
}

int SocketMulticast :: recibe(PaqueteDatagrama & p){
    unsigned int len = sizeof(direccionForanea);
    int salida = recvfrom(s, (char*) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr*) &direccionForanea, &len);
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    return salida;
}

int SocketMulticast :: recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos){
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

int SocketMulticast::envia(PaqueteDatagrama & p, unsigned char ttl){
    setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = PF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons( p.obtienePuerto() );
    return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
        
void SocketMulticast::unirseGrupo(char * IPmulticast){
    struct ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IPmulticast);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
}
        
void SocketMulticast::salirseGrupo(char * IPmulticast){
    struct ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IPmulticast);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
}