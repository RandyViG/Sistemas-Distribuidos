cliente:	cliente.cpp Solicitud.o SocketDatagrama.o PaqueteDatagrama.o
		g++ -std=c++11 cliente.cpp Solicitud.o SocketDatagrama.o PaqueteDatagrama.o -o cliente -lpthread
Solicitud.o:	Solicitud.cpp Solicitud.h
		g++ -c Solicitud.cpp
SocketDatagrama.o:	SocketDatagrama.cpp SocketDatagrama.h
			g++ -c SocketDatagrama.cpp
PaqueteDatagrama.o:	PaqueteDatagrama.cpp PaqueteDatagrama.h
			g++ -c PaqueteDatagrama.cpp
clean:
	rm -f *.o cliente
