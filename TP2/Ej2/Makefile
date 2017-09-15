# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
OFLAGS= -c -g -ggdb -Wall -std=c++11
CFLAGS = -g -ggdb -Wall -std=c++11

SOURCES = bfmod.o

all: ej2 tests

ej2: $(SOURCES) main.o
	$(CC) $(CFLAGS) $(SOURCES) main.o -o Ej2

Ej2.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

tests: $(SOURCES) tests.o
	$(CC) $(CFLAGS) $(SOURCES) tests.o -o tests

tests.o: tests.cpp
	$(CC) $(OFLAGS) tests.cpp

bfmod.o: bfmod.cpp bfmod.h
	$(CC) $(OFLAGS) bfmod.cpp bfmod.h

clean:
	rm *.o
	rm Ej2

