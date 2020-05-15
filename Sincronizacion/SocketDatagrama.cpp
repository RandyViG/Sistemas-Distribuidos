#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

SocketDatagrama :: SocketDatagrama(int pto) {
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	bzero((char *)&direccionForanea, sizeof(direccionForanea));

	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
		perror("socket creation failed"); 
		exit(-1); 
	}

	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(pto);

	if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)) < 0 ) { 
		perror("bind failed"); 
		exit(-1); 
	}
}

SocketDatagrama :: ~SocketDatagrama() {
	close(s);
}

int SocketDatagrama :: recibe(PaqueteDatagrama &p) {
	unsigned int len = sizeof(direccionForanea);
	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, &len);
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	p.inicializaPuerto( ntohs(direccionForanea.sin_port) );
	return rec;
}

int SocketDatagrama ::recibeTimeout( PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos ){
	unsigned int len;
	int n;
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
	len = sizeof(direccionForanea);
	n = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, &len);
	if( n < 0 ){
		if( errno == EWOULDBLOCK ){
			fprintf(stderr, "\nTiempo para recepción transcurrido\n");
			return -1;
		}
		else
			fprintf(stderr, "\nError en recvfrom\n");
	}
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	p.inicializaPuerto( ntohs(direccionForanea.sin_port) );
	return n;
}

int SocketDatagrama :: envia(PaqueteDatagrama &p) {
   	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons( p.obtienePuerto() );
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}