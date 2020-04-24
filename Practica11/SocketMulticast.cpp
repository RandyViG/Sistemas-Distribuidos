#include <iostream>
#include "SocketMulticast.h"
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

SocketMulticast :: SocketMulticast(int p){
    id = 0;
    puertoUnicast = 2700;
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

int SocketMulticast :: recibe( PaqueteDatagrama & p ){
    unsigned int len = sizeof(direccionForanea);
    int salida = recvfrom(s, (char*) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr*) &direccionForanea, &len);
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    return salida;
}

int SocketMulticast :: recibeConfiable( PaqueteDatagrama &p ){
    struct mensaje msj;
    unsigned int len = sizeof(direccionForanea);
    int salida = recvfrom(s, (char*) p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr*) &direccionForanea, &len);
    if ( salida > 0 ){
        p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
        p.inicializaPuerto(ntohs(direccionForanea.sin_port));
        memcpy( &msj , p.obtieneDatos() , sizeof(msj) );
        PaqueteDatagrama respuesta( (char*)&id , 1 , p.obtieneDireccion() , puertoUnicast );
        sd = new SocketDatagrama( 0 );
        sd->envia(respuesta);
        sd->~SocketDatagrama();
        if( msj.requestId < id ){
            return -1;
        }
        else
            id++;
    }
    return salida;
}

int SocketMulticast :: enviaConfiable(PaqueteDatagrama &p, unsigned char ttl, int num_receptores){
    int respuesta,pes;
    struct mensaje deposito;
    deposito.requestId = id;
    memcpy(deposito.arguments,p.obtieneDatos(),p.obtieneLongitud());
    setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = PF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons( p.obtienePuerto() );
    int enviar = sendto(s, (char *)&deposito, sizeof(deposito) * sizeof(char), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
    sd = new SocketDatagrama( puertoUnicast );
    PaqueteDatagrama pd(1);
    for( int i = 0 ; i < num_receptores ; i++ ){
        if( sd->recibeTimeout(pd,2,500000) == -1 ){
            sd->~SocketDatagrama();
            return -1;
        }
    }
    id++;
    sd->~SocketDatagrama();
    return enviar;
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