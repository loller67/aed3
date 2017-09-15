# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
OFLAGS= -c -g -ggdb -Wall -std=c++11
CFLAGS = -g -ggdb -Wall -std=c++11

SOURCES = ../aux/AdyMatrix/AdyMatrix.o heuristicaGolosa.o ../aux/Solucion/Solucion.o

all: ej2 tests

ej2: $(SOURCES) main.o
	$(CC) $(CFLAGS) $(SOURCES) main.o -o Ej2

Ej2.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

../aux/AdyMatrix/AdyMatrix.o: ../aux/AdyMatrix/AdyMatrix.h ../aux/AdyMatrix/AdyMatrix.cpp
	$(CC) $(OFLAGS) ../aux/AdyMatrix/AdyMatrix.cpp -o ../aux/AdyMatrix/AdyMatrix.o

../aux/Generadores/generador.o: ../aux/Generadores/generador.h ../aux/Generadores/generador.cpp
	$(CC) $(OFLAGS)  ../aux/Generadores/generador.cpp -o ../aux/Generadores/generador.o

heuristicaGolosa.o: heuristicaGolosa.h heuristicaGolosa.cpp
	$(CC) $(OFLAGS) heuristicaGolosa.cpp -o heuristicaGolosa.o

../aux/Solucion/Solucion.o: ../aux/Solucion/Solucion.h ../aux/Solucion/Solucion.cpp
	$(CC) $(OFLAGS) ../aux/Solucion/Solucion.cpp -o ../aux/Solucion/Solucion.o

tests: $(SOURCES) ../aux/Generadores/generador.o ../Ej1/Exacto.o tests.o
	$(CC) $(CFLAGS) $(SOURCES) ../aux/Generadores/generador.o ../Ej1/Exacto.o tests.o -o tests

../Ej1/Exacto.o: ../Ej1/Exacto.h ../Ej1/Exacto.cpp
	$(CC) $(OFLAGS) ../Ej1/Exacto.cpp -o ../Ej1/Exacto.o

tests.o: tests.cpp
	$(CC) $(OFLAGS) tests.cpp

clean:
	rm ../aux/AdyMatrix/AdyMatrix.o
	rm ../aux/Generadores/generador.o
	rm ../aux/Solucion/Solucion.o
	rm *.o
	rm Ej2
	rm tests