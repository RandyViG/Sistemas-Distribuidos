servidor:	servidor.cpp mongoose.o
	g++ servidor.cpp mongoose.c -o servidor
	./servidor
mongoose.o:	mongoose.c mongoose.h
	gcc -c mongoose.c
clean:
	rm -rf servidor *.o
