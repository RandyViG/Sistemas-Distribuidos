#ifndef SOCKET_MULTICAST_H_
#define SOCKET_MULTICAST_H_
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>

class SocketMulticast{
    private:
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        struct timeval timeout;
        int s;
    public:
        SocketMulticast(int);
        ~SocketMulticast();
        int recibe(PaqueteDatagrama & p);
        int recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos);
        int envia(PaqueteDatagrama & p, unsigned char ttl);
        void unirseGrupo(char *);
        void salirseGrupo(char *);
};
#endif