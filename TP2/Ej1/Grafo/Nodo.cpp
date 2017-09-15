
#include <vector>
#include "Nodo.h"
#include "Eje.h"
#include <iostream>

using namespace std;

//O(1)
Nodo::Nodo(int identificador){
	t_identificador = identificador;
	t_peso_acumulado = -1;
	t_ejes_de_salida = vector<Eje>();

}

//O( longitud(t_ejes_de_salida) )
Nodo::~Nodo(){}

//O(1)
void Nodo::agregar_eje_direccional(Nodo* nodo_destino, int peso){
	Eje eje = Eje(nodo_destino, peso);
	t_ejes_de_salida.push_back( eje );
}

//O(1)
int Nodo::identificador(){
	return t_identificador;
}

//O( longitud( t_ejes_de_salida) )
vector<Eje> Nodo::ejes_de_salida(){
	return t_ejes_de_salida;
}

//O(1)
int Nodo::obtener_peso_acumulado(){
	return t_peso_acumulado;
}

//O(1)
void Nodo::establecer_peso_acumulado(int peso_acumulado_nuevo){
	t_peso_acumulado = peso_acumulado_nuevo;
}
