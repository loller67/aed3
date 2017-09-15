CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
OFLAGS= -c -g -ggdb -Wall -std=c++11
CFLAGS = -g -ggdb -Wall -std=c++11

SOURCES = main.o

SOURCESTEST = tester.o

Ej3: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o Ej3


tests: $(SOURCESTEST)
	$(CC) $(CFLAGS) $(SOURCESTEST) -o tests

*.o: *.cpp
	$(CC) $(OFLAGS) *.cpp

clean:
	rm -f *.o
	rm -f Ej3
	rm -f tests

