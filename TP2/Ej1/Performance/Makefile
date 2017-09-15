# Compilador que será utilizado
CC=g++

LDFLAGS=
INCDIR=

# flags de compilación
CFLAGS=-g -Wall -std=c++11


# Agregar acá los archivos .cpp a compilar
GRAFO = ../Grafo/Digrafo.cpp ../Grafo/Eje.cpp ../Grafo/Nodo.cpp
ESTRUCTURA = ../Estructura/Estructura.cpp
DIJKSTRA = ../Dijkstra/Dijkstra.cpp
PERFORMANCE = ../Performance/data_manager.cpp ../Performance/fixedKCases.cpp ../Performance/fixedNCases.cpp ../Performance/performance.cpp
TESTS = ../Tests/test.cpp
TOOLS = ../file_manager.cpp ../tools.cpp
MAIN = ../main.cpp

# Objetos que serán generados
PROBLEM_OBJECTS = $(GRAFO:.cpp=.o) $(ESTRUCTURA:.cpp=.o) $(DIJKSTRA:.cpp=.o) $(TOOLS:.cpp=.o)
PERFORMANCE_OBJECTS = $(PROBLEM_OBJECTS) $(PERFORMANCE:.cpp=.o)
TESTS_OBJECTS = $(PROBLEM_OBJECTS) $(TESTS:.cpp=.o)
MAIN_OBJECTS = $(PROBLEM_OBJECTS) $(MAIN:.cpp=.o)

# Nombre del ejecutable a generar
EX1_EXECUTABLE= Ej1
TEST_EXECUTABLE = tests
PERFORMANCE_EXECUTABLE = performance

all: $(MAIN_OBJECTS) $(PERFORMANCE_EXECUTABLE) 
	
$(PERFORMANCE_EXECUTABLE): $(PERFORMANCE_OBJECTS)
	$(CC) $(LDFLAGS) $(PERFORMANCE_OBJECTS) -o $@
clean:
	rm -rf $(PERFORMANCE_EXECUTABLE) $(MAIN_OBJECTS) $(PERFORMANCE_OBJECTS) $(PROBLEM_OBJECTS) $(TESTS_OBJECTS)

.cpp.o:
	$(CC) -I$(INCDIR) $(CFLAGS) $< -c -o $@

