server:	server_HTTP.o mongoose.o SocketDatagrama.o PaqueteDatagrama.o
		g++ server_HTTP.o mongoose.o SocketDatagrama.o PaqueteDatagrama.o -o server_HTTP
server_HTTP:	server_HTTP.cpp
		g++ -c server_HTTP.cpp
mongoose.o:	mongoose.c mongoose.h
		gcc -c mongoose.c
Respuesta.o:	Respuesta.cpp Respuesta.h
		g++ -c Respuesta.cpp
SocketDatagrama.o:	SocketDatagrama.cpp SocketDatagrama.h
		g++ -c SocketDatagrama.cpp
PaqueteDatagrama.o:	PaqueteDatagrama.cpp PaqueteDatagrama.h
		g++ -c PaqueteDatagrama.cpp
clean:
	rm -f *.o server_HTTP

