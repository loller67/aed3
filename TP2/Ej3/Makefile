# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
OFLAGS= -c -g -ggdb -Wall -std=c++11
CFLAGS = -g -ggdb -Wall -std=c++11

SOURCES = main.o ../aux/parser.o ../aux/AdyacencyList/AdyacencyList.o

ej3: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o Ej3

Ej3.o: Ej3.cpp
	$(CC) $(OFLAGS) Ej3.cpp

../graphs/AdyacencyList/AdyacencyList.o: ../aux/AdyacencyList/AdyacencyList.h ../aux/AdyacencyList/AdyacencyList.cpp
	$(CC) $(OFLAGS) ../aux/AdyacencyList/AdyacencyList.cpp -o ../aux/AdyacencyList/AdyacencyList.o

clean:
	rm ../aux/AdyacencyList/AdyacencyList.o
	rm Ej3




#mi compliacion con crono funciona con este comando g++ -std=c++11 ../aux/parser.o ../aux/AdyacencyList/AdyacencyList.o  tests.cpp -o Ej3
#No se porque, hay que revisar
