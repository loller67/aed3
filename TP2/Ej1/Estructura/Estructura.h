#ifndef AED3TP21C2017_EJ1_ESTRUCTURA_ESTRUCTURA_H_
#define AED3TP21C2017_EJ1_ESTRUCTURA_ESTRUCTURA_H_

#include "../Grafo/Digrafo.h"
#include "../Grafo/Nodo.h"
#include "../Grafo/Eje.h"
#include <vector>
#include <string>

using namespace std;



class Estructura{

private:

	/***Atributos****/
	vector<Digrafo> t_estructura;
	 int t_origen;
	 int t_destino;

	/****Funciones privadas****/
	 int hacer_dijkstra();
	 int obtener_resultado();

public:

	/****Constructores y destructores****/
	Estructura(int cantidad_de_pisos, int cantidad_de_nodos_por_piso, int origen, int destino);
	Estructura(string filename);

	~Estructura();

	/****Funciones publicas****/
	void conectar_nodos_con_ruta_comun(int origen, int destino, int peso);
	void conectar_nodos_con_ruta_premium(int origen, int destino, int peso);

	Nodo* obtener_nodo_origen();
	int resolver();
};



#endif /* AED3TP21C2017_EJ1_ESTRUCTURA_ESTRUCTURA_H_ */
