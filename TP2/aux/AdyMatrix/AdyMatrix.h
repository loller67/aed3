#ifndef _ADY_MATRIX_H_
#define _ADY_MATRIX_H_


#include "../../Ej1/includes.h"
#include <vector>

using namespace std;

class AdyMatrix {
public:
	AdyMatrix();
	AdyMatrix(int n);
	AdyMatrix(int n, int k);
	~AdyMatrix();

	void addEdge(int n1, int n2);
	void addEdge(int n1, int n2, int w);
	void set(int i,int j,int val);
	int get (int i,int j);
	void print();

private:

	vector<vector<int> > matrix;
	int nodesQ;
	int edgesQ;

};

#endif
