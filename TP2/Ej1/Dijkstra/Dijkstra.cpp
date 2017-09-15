
#include <stddef.h>
#include <vector>
#include <iostream>
#include "../Grafo/Digrafo.h"
#include "../Grafo/Eje.h"
#include "../Grafo/Nodo.h"
#include "Dijkstra.h"


Dijkstra::Dijkstra() {}

Dijkstra::~Dijkstra() {}


void Dijkstra::iniciar_dijkstra(Nodo* nodo){

	nodo->establecer_peso_acumulado(0);
	t_cola.push_back(nodo);

	continuar_dijkstra();
}


/*
	//O( vecinos_del_menor  ) + recursion
	Notemos n = cantidad de nodos
	Notemos m = cantidad de ejes. Sabemos que m pertenece a O(n^2)
	Acotemos t_cola.size por n.
	Sabemos que los nodos pueden estar en la cola una sola vez. Por lo que se itera cada eje a lo sumo una vez.
	Luego la complejidad total es tener complejidad O(1 ) por cada eje. Luego, se tienen m ejes y la complejidad es 
	O( m * 1) y como m pertenece a O(n^2), la complejidad total es O(n^2)
*/
void Dijkstra::continuar_dijkstra(){

	if(t_cola.empty()){
		return;
	}
	else{

		Nodo* nodo = obtener_menor(); //O( t_cola.size() )

		vector<Eje> ejes = nodo->ejes_de_salida(); //O( cantidad de vecinos)

		for(int i = 0; i < (int) ejes.size(); i++){ //O( cantidad de vecinos * 1 )
			Eje* actual = &ejes[i]; //O(1)
			analizar_y_agregar_nodo(actual, nodo->obtener_peso_acumulado() ); //O( 1 )
		}
	}

	continuar_dijkstra(); //O(1)

}

//O( t_cola.size )
Nodo* Dijkstra::obtener_menor(){
	Nodo* menor = t_cola[0];
	int mejor_acum = menor->obtener_peso_acumulado(); //O(1)

	for(int i = 1; i < (int) t_cola.size(); i++){ //O( t_cola.size )
		Nodo* actual = t_cola[i];
		int acum_actual = actual->obtener_peso_acumulado(); //O(1)

		if(acum_actual < mejor_acum){
			menor = actual;
			mejor_acum = acum_actual;
		}
	}

	sacar_nodo_de_cola(menor); //O( t_cola.size )
	return menor;
}

//O(t_cola.size )
void Dijkstra::sacar_nodo_de_cola(Nodo* nodo){

	vector<Nodo*> t_cola_nueva;
	for(int i = 0; i < (int) t_cola.size(); i++){ //O( t_cola.size )
		Nodo* nodo_actual = t_cola[i];
		if(nodo == nodo_actual){

		}
		else{
			t_cola_nueva.push_back(nodo_actual);
		}
	}

	t_cola = t_cola_nueva;
}

//O( 1 )
void Dijkstra::analizar_y_agregar_nodo(Eje* eje, int peso_acumulado){
	int peso_eje = eje->peso(); 
	Nodo* nodo_eje = eje->destino();
	int peso_acumulado_nodo = nodo_eje->obtener_peso_acumulado(); //O(1)

	int peso_total = peso_eje + peso_acumulado;

	if(peso_acumulado_nodo > peso_total || peso_acumulado_nodo == -1){
		agregar_nodo_a_cola_si_no_esta_agregado(nodo_eje); //O( 1 )
		nodo_eje->establecer_peso_acumulado(peso_total); //O(1)
	}
}

//O( t_cola.size )
void Dijkstra::agregar_nodo_a_cola_si_no_esta_agregado(Nodo* nodo){

	bool nodo_esta = nodo->obtener_peso_acumulado() > -1; //O(1 )
	if(!nodo_esta){
		t_cola.push_back(nodo);
	}
}

//O( t_cola.size() )
bool Dijkstra::nodo_esta_en_cola(Nodo* nodo){
	bool res = false;

	for(int i = 0; i< (int) t_cola.size(); i++){
		res = res || nodo == t_cola[i];
	}

	return res;
}



