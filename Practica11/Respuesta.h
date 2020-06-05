#ifndef __RESPUESTA_H__
#define __RESPUESTA_H__

#include "SocketDatagrama.h"
#include "mensaje.h"

class Respuesta{
    private:
        char ip[16];
        int ptoDestino;
        SocketDatagrama *socketlocal;
    public:
        Respuesta(int pl);
        struct mensaje *getRequest(void);
        void sendReply(char *respuesta);
};

#endif