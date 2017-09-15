
#ifndef AED3TP21C2017_EJ1_GRAFO_EJE_H_
#define AED3TP21C2017_EJ1_GRAFO_EJE_H_

#include "Nodo.h"

using namespace std;

class Nodo;
class Eje {

public:

	/****Constructores y destructores****/
	Eje( Nodo* destino, int peso);
	~Eje();

	/****Funciones publicas****/
	Nodo* destino();
	int peso();

private:

	/****Atributos****/
	Nodo* t_destino;
	int t_peso;

};


#endif /* AED3TP21C2017_EJ1_GRAFO_EJE_H_ */
