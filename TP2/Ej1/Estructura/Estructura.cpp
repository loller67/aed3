/*
 * Estructura.cpp
 *
 *  Created on: May 6, 2017
 *      Author: itu
 */
#include "../Grafo/Digrafo.h"
#include "../Grafo/Nodo.h"
#include "../Grafo/Eje.h"
#include <vector>
#include "../Dijkstra/Dijkstra.h"
#include "../tools.h"
#include "Estructura.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



Estructura::Estructura(string filename) {


	ifstream myfile;
	myfile.open(filename.c_str());

	vector<int> first_line = get_ints_grom_file(myfile);
	int n = first_line[0];
	int m = first_line[1];

	vector<int> second_line = get_ints_grom_file(myfile);
	int origen = second_line[0];
	int destino = second_line[1];
	int k = second_line[2];

	for(int i = 0; i <= k; ++i) {
		Digrafo piso_nuevo = Digrafo( n );
		t_estructura.push_back(piso_nuevo);
	}

	t_origen = origen;
	t_destino = destino;

	for(int i = 0; i < m; i++){
		vector<int> arista = get_ints_grom_file(myfile);
		int a = arista[0];
		int b = arista[1];
		int p = arista[2];
		int d = arista[3];

		if(p == 0){
			this->conectar_nodos_con_ruta_comun(a, b, d);
		}
		else{
			this->conectar_nodos_con_ruta_premium(a, b, d);
		}
	}
}

//O( cantidad_de_nodos_por_piso * cantidad_de_pisos)
Estructura::Estructura(int cantidad_de_pisos, int cantidad_de_nodos_por_piso, int origen, int destino) {


	for(int i = 0; i <= cantidad_de_pisos; ++i) { //O( cantidad_de_nodos_por_piso * cantidad_de_pisos)
		Digrafo piso_nuevo = Digrafo( cantidad_de_nodos_por_piso ); //O( cantidad_nodos_por_piso )
		t_estructura.push_back(piso_nuevo); //O(cantidad_nodos_por_piso)
	}

	t_origen = origen;
	t_destino = destino;
}

Estructura::~Estructura() {}

//O( cantidad de pisos)
void Estructura::conectar_nodos_con_ruta_comun(int origen, int destino, int peso){

	for(int i = 0; i < (int) t_estructura.size(); i++){
		t_estructura[i].conectar_nodo_con(origen, destino, peso);
		t_estructura[i].conectar_nodo_con(destino, origen, peso);
	}
}

//O( cantidad de pisos)
void Estructura::conectar_nodos_con_ruta_premium(int origen, int destino, int peso) {

	//O(cantidad de pisos)
	for(int i = 0; i < (int) t_estructura.size()-1 ; i++){
		Nodo* nodo_piso_inferior = t_estructura[i].obtener_nodo(origen);
		Nodo* nodo_piso_superior = t_estructura[i+1].obtener_nodo(destino);

		nodo_piso_inferior->agregar_eje_direccional(nodo_piso_superior, peso);
	}

	//O(cantidad de pisos)
	for(int i = 0; i < (int) t_estructura.size()-1 ; i++){
		Nodo* nodo_piso_inferior = t_estructura[i].obtener_nodo(destino);
		Nodo* nodo_piso_superior = t_estructura[i+1].obtener_nodo(origen);

		nodo_piso_inferior->agregar_eje_direccional(nodo_piso_superior, peso);
	}

}

//O(1)
Nodo* Estructura::obtener_nodo_origen(){
	Nodo* nodo = t_estructura[0].obtener_nodo(t_origen);
	return nodo;
}

//O( (cantidad de nodos*k) ^2 )
int Estructura::hacer_dijkstra(){
	Nodo* origen = obtener_nodo_origen();
	Dijkstra resolvedor = Dijkstra();
	resolvedor.iniciar_dijkstra(origen); //O( nodos*pisos ^2)

	int distancia_minima = obtener_resultado();

	return distancia_minima;
}

//O( cantidad de pisos)
int Estructura::obtener_resultado(){

	int mejor_distancia = -1;

	for(int i = 0; i < (int) t_estructura.size(); i++){
		Nodo* destino_piso_i = t_estructura[i].obtener_nodo(t_destino);
		int i_acumulado = destino_piso_i->obtener_peso_acumulado();

		if(i_acumulado != -1 ){
			if(mejor_distancia == -1){
				mejor_distancia = i_acumulado;
			}
			else{
				if(mejor_distancia > i_acumulado){
					mejor_distancia = i_acumulado;
				}
			}
		}
	}

	return mejor_distancia;
}

//O( (n*k)^2 )
int Estructura::resolver(){
	return hacer_dijkstra();
}


