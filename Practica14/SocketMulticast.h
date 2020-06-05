#ifndef SOCKET_MULTICAST_H_
#define SOCKET_MULTICAST_H_
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "mensaje.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include "PaqueteDatagrama.h"

class SocketMulticast{
    private:
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        struct timeval timeout;
        SocketDatagrama *sd;
        int s;
        int id;
        int puertoUnicast;
    public:
        SocketMulticast(int);
        ~SocketMulticast();
        int recibe(PaqueteDatagrama & p);
        int recibeConfiable(PaqueteDatagrama & p);
        int enviaConfiable(PaqueteDatagrama & p, unsigned char ttl, int num_receptores);
        int envia(PaqueteDatagrama & p, unsigned char ttl);
        void unirseGrupo(char *);
        void salirseGrupo(char *);
};
#endif