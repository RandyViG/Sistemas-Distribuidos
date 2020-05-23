#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_
#include "PaqueteDatagrama.h"
#include <netinet/in.h>

class SocketDatagrama {
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		struct timeval timeout;
		int s;
	public:
		SocketDatagrama(int);
		~SocketDatagrama();
		int recibe(PaqueteDatagrama & p);
		int envia(PaqueteDatagrama & p);
		int recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos);

}; 
#endif