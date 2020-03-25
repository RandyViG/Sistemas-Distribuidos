run: cliente.cpp servidor.cpp SocketDatagrama.o
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o -o servidor
	g++ cliente.cpp SocketDatagrama.o PaqueteDatagrama.o -o cliente

SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c 

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
clean:
	rm -f *.o cliente servidor
