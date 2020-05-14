#ifndef __SOLICITUD_H__
#define __SOLICITUD_H__

#include "SocketDatagrama.h"

class Solicitud{
    private:
        int id = 0;
        SocketDatagrama *socketlocal;
    public:
        Solicitud();
        char * doOperation(char *IP, int puerto, int operationId, char *arguments );
};

#endif