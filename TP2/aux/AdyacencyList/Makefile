# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
OFLAGS=-c -g -ggdb -Wall -std=c++11
CFLAGS = -g -ggdb -Wall -std=c++11

adyacencyListTest: AdyacencyList.cpp AdyacencyList.h 
	$(CC) $(CFLAGS) AdyacencyList.cpp AdyacencyList.h -o adyacencyList

clean:
	rm adyacencyList
