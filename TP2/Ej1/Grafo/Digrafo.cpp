
#include "Digrafo.h"
#include <vector>
#include "Eje.h"
#include "Nodo.h"

using namespace std;


//O(1)
Digrafo::Digrafo(){
	t_siguiente_identificador = 1;
}

//O( cantidad de nodos )
Digrafo::Digrafo(int cantidad_de_nodos){
	t_siguiente_identificador = 1;
	for(int i =0; i < cantidad_de_nodos; i++){
		agregar_nodo_sin_vecinos();
	}
}

//O(1)
void Digrafo::agregar_nodo_sin_vecinos(){
	Nodo new_nodo = Nodo(t_siguiente_identificador); //O(1)
	t_nodos.push_back(new_nodo); //O(1)
	t_siguiente_identificador++; //O(1)
}

//O(1)
void Digrafo::conectar_nodo_con(int origen, int destino, int peso){
	Nodo* nodo_origen = &t_nodos[origen-1]; //O(1)
	Nodo* nodo_destino = &t_nodos[destino-1]; //O(1)

	conectar_nodo_con(nodo_origen, nodo_destino, peso); //O(1)
}

//O(1)
void Digrafo::conectar_nodo_con(Nodo* origen, Nodo* destino, int peso){
	origen->agregar_eje_direccional(destino, peso);//O(1)
}

//O(1)
Nodo* Digrafo::obtener_nodo(int identificador){
	Nodo* nodo = &t_nodos[identificador-1];
	return nodo;
}





