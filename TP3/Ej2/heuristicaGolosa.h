#ifndef _H_GOLOSA_H_
#define _H_GOLOSA_H_

#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <utility>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <climits>
#include <vector>
#include <iostream>
#include "../aux/AdyMatrix/AdyMatrix.h"
#include "../aux/Solucion/Solucion.h"


using namespace std;

Solucion hGolosa(AdyMatrix& a, int n);
bool esClique(AdyMatrix& A, vector<int>& clique, int v);
int grado(AdyMatrix& A, int v);

#endif