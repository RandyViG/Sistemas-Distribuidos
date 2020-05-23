#ifndef __RESPUESTA_H__
#define __RESPUESTA_H__

#include "SocketDatagrama.h"
#include "mensaje.h"

class Respuesta{
    private:
        char ip[16];
        int ptoDestino;
        int id = 0;
        int error = 0;
        SocketDatagrama *socketlocal;
    public:
        Respuesta(int pl);
        int getError( void );
        struct mensaje *getRequest(void);
        void sendReply(char *respuesta);
};

#endif