# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
OFLAGS=-c -g -ggdb -Wall -std=c++0x
CFLAGS = -g -ggdb -Wall -std=c++0x

main: ../AdyMatrix/AdyMatrix.cpp generador.cpp main.cpp
	$(CC) $(CFLAGS) ../AdyMatrix/AdyMatrix.cpp generador.cpp main.cpp -o main

clean: 
	rm -f ../AdyMatrix/AdyMatrix.o generador.o main