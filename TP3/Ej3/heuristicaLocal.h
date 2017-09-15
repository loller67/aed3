#ifndef _H_LOCAL_H_
#define _H_LOCAL_H_

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
#include "../Ej2/heuristicaGolosa.h"


using namespace std;

Solucion hLocal(AdyMatrix& A, Solucion& s, int n);
bool esClique(AdyMatrix& A, vector<int>& clique, int v, int ignore);

#endif