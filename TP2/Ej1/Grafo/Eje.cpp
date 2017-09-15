/*
 * Ejes.cpp
 *
 *  Created on: May 6, 2017
 *      Author: itu
 */

#include "Eje.h"
#include "Nodo.h"


//O(1)
Eje::Eje(Nodo* destino, int peso) {
	t_destino = destino;
	t_peso = peso;

}

Eje::~Eje(){}

//O(1)
Nodo* Eje::destino(){
	return t_destino;
}

//O(1)
int Eje::peso(){
	return t_peso;
}



