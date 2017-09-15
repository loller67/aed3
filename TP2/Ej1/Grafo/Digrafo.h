#ifndef _DIGRAFO_H_EJ1_
#define _DIGRAFO_H_EJ1_

#include <vector>
#include "Nodo.h"

using namespace std;

class Digrafo{

private:

	 /****Atributos****/
	int t_siguiente_identificador;
	vector<Nodo> t_nodos;


public:

	/****Constructores y destructores****/
	Digrafo();
	Digrafo(int cantidad_de_nodos);
	~Digrafo(){}

	/****Funciones publicas****/
	void agregar_nodo_sin_vecinos();
	void conectar_nodo_con(int origen, int destino, int peso);
	void conectar_nodo_con(Nodo* origen, Nodo* destino, int peso);
	Nodo* obtener_nodo(int indice);

};

#endif
