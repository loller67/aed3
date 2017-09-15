#ifndef EXACTO
#define EXACTO

#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <vector>
#include <list>
#include <iostream>
#include "../aux/AdyMatrix/AdyMatrix.h"
#include "../aux/Solucion/Solucion.h"


using namespace std;

void print( vector<int> l);
void saver(list < vector < int > > &conjunto, vector <int> &l);
void subset(vector<int>, int size, int left, int index, vector<int> &l, list < vector < int > > &conjunto);
bool esClique(AdyMatrix & A, vector<int>& clique, int v, int n);
void getInputEj1(AdyMatrix &matriz,int n, int m);
void EliminarNoCliques(AdyMatrix & matriz,list < vector < int > > &conjunto);
vector <int> Grados(AdyMatrix &matriz,int n);
int gradosInternos(int k);
int gradosExternos(vector <int> &grados,int gradosInternos, vector<int> &clique);
Solucion SolucionMaxima(vector <int> &grados,int k,list < vector < int > > cliques);
Solucion SolucionExacta(AdyMatrix &matriz,int n,int m,int k);
Solucion Ej1(AdyMatrix &M,int n,int m);
#endif
