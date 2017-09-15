#ifndef AED3TP21C2017_EJ1_GRAFO_NODO_H_
#define AED3TP21C2017_EJ1_GRAFO_NODO_H_

#include <vector>
#include "Eje.h"


using namespace std;

class Eje;
class Nodo{

public:

	/****Constructores y destructores****/
	Nodo(int identificador);
	~Nodo();

	/****Funciones publicas****/
	int identificador();
	void agregar_eje_direccional(Nodo* nodo, int peso);
	vector< Eje > ejes_de_salida();
	int obtener_peso_acumulado();
	void establecer_peso_acumulado(int peso_acumulado_nuevo);

private:

	/****Atributos****/
	int t_identificador;
	int t_peso_acumulado;
	vector<Eje> t_ejes_de_salida;



};

#endif /* AED3TP21C2017_EJ1_GRAFO_NODO_H_ */
