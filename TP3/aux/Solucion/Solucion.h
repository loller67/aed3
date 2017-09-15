#ifndef _SOLUCION_H_
#define _SOLUCION_H_


#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>

using namespace std;

class Solucion {
public:
	int F;
	int k;
	vector<int> v;

	Solucion(){F = 0; k = 0;}
	void print();

	friend ostream& operator<<(ostream& os, const Solucion& s);
	void operator=(Solucion s){F = s.F; k = s.k; v = s.v;}

};

#endif
