#ifndef _BFMOD_H_
#define _BFMOD_H_


#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <utility>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

class Arista
{
	public:
		int origen;
		int destino;
		int peso;

	Arista(int o, int d, int p){origen = o; destino = d; peso = p;}
	void print(){cout << origen << " --" << peso << "-> " << destino << endl;}
};

bool BellmanFordModificado(int n, int m, vector<Arista> &aristas, int resta);
int ejercicio2(int n, int m, int cmin, int cmax, vector<Arista> &aristas);

#endif