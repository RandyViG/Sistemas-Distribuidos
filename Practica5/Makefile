prac_campo: prac_campo.cpp Rectangulo.o
			g++ prac_campo.cpp Rectangulo.o Coordenada.o -o prac_campo
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
			g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
			g++ Coordenada.cpp -c
clean:
		rm -f *.o prac_campo 