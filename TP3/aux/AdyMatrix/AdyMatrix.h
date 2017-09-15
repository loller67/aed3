#ifndef _ADY_MATRIX_H_
#define _ADY_MATRIX_H_


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

class AdyMatrix {
public:
	AdyMatrix();
	AdyMatrix(int n);
	AdyMatrix(const AdyMatrix&);
	AdyMatrix(int n, int k);
	~AdyMatrix();
	
	void grafoCompleto();
	void addEdge(int n1, int n2);
	void addEdge(int n1, int n2, int w);
	void set(int i,int j,int val);
	int get (int i,int j);
	void print();
	int& operator() (int x, int y);
	void operator=(AdyMatrix aM);
	int size(){return nodesQ;}
	AdyMatrix diferencia(vector<int>& v);
	void erase(vector<int>& v);
	void add(vector<int>& a);
	void add(AdyMatrix& M, int a);
	void removeNode(int a);
	int aristas(){return edgesQ;}
	void removeEdge(int i1, int j2);
	void shuffleViejo();
	void shuffle();

	int aristas2();
	int degree(int index);
private:

	vector<vector<int> > matrix;
	int nodesQ;
	int edgesQ;

};

#endif
