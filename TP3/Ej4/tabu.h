#ifndef _TABU_H_
#define _TABU_H_

#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <utility>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>    // std::sort
#include "../aux/AdyMatrix/AdyMatrix.h"
#include "../aux/Solucion/Solucion.h"
#include "../Ej2/heuristicaGolosa.h"
#include "../Ej3/heuristicaLocal.h"


using namespace std;

//Solucion hTabu(AdyMatrix& A, int n);


Solucion hTabu(AdyMatrix& A, int n, int k, int& maxRep);

Solucion hTabu1(AdyMatrix& A, int n, int k, int& maxRep);
Solucion hTabu2(AdyMatrix& A, int n, int k, int& maxRep);

Solucion hTabu3(AdyMatrix& A, int n, int k, int& maxRep, int n2t);


//Solucion hGolosa2(AdyMatrix& Modif, AdyMatrix& Full, int n);

#endif