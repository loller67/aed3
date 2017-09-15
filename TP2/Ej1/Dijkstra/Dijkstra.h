/*
 * Dijkstra.h
 *
 *  Created on: May 6, 2017
 *      Author: itu
 */

#ifndef AED3TP21C2017_EJ1_DIJKSTRA_DIJKSTRA_H_
#define AED3TP21C2017_EJ1_DIJKSTRA_DIJKSTRA_H_

#include <vector>
#include "../Grafo/Digrafo.h"
#include "../Grafo/Eje.h"
#include "../Grafo/Nodo.h"

class Dijkstra {

private:

	/****Atributos****/
	vector<Nodo*> t_cola;

	void sacar_nodo_de_cola(Nodo* nodo);


public:

	/****Constructores y destructores****/
	Dijkstra();
	~Dijkstra();

	void iniciar_dijkstra(Nodo* nodo);

private:

	void analizar_y_agregar_nodo(Eje* eje_del_nodo_actual, int peso_acumulado_nodo_actual );
	void agregar_nodo_a_cola_si_no_esta_agregado(Nodo* nodo);
	bool nodo_esta_en_cola(Nodo* nodo);
	void continuar_dijkstra();
	Nodo* obtener_menor();

};




#endif /* AED3TP21C2017_EJ1_DIJKSTRA_DIJKSTRA_H_ */
