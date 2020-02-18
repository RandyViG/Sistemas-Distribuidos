programa6:	 programa6.cpp PoligonoIrregular.o Coordenada.o
		g++ programa6.cpp PoligonoIrregular.o Coordenada.o -o programa6
PoligonoIrregular.o:	PoligonoIrregular.cpp PoligonoIrregular.h
		g++ -c  PoligonoIrregular.cpp
Coordenada.o:	Coordenada.cpp Coordenada.h
		g++ -c Coordenada.cpp
clean:
	rm -f *.o programa6

