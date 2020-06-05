#ifndef __MENSAJE_H__
#define __MENSAJE_H__

#define TAM_MAX_DATA 4
#define suma 1

struct mensaje{
    int messageType;
    unsigned int requestId;
    int operationId;
    char arguments[TAM_MAX_DATA];
};

#endif