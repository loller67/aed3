#include "Exacto.h"



//O(m)
void getInputEj1(AdyMatrix &Matriz,int n, int m) {

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		a = a-1;
		b = b-1;
		Matriz.addEdge(min(a,b),max(a,b));
    }
}

//O(n^2)
vector <int> Grados(AdyMatrix &matriz,int n){
	vector<int> Gr;
	for (int  i = 0; i < n; i++) {
		int cantidad = 0;
		for (int  j = 0; j < n; j++) {
			if (i != j) {
				if (matriz.get(i,j) != 0) {
					cantidad++;
				}
			}
		}
		Gr.push_back(cantidad);
	}
	return Gr;
}

//O(1)
int gradosInternos(int k) {

	return k-1;
}

//O(size(v))
int MaximoGrado(vector < int > &v,int &nodoMax) {
	int max = 0;
	for (unsigned int  i = 0; i < v.size(); i++) {
		if (max < v[i]) {
			max = v[i];
			nodoMax = i;
		}
	}
	return max;
}

//O(size(clique))
int gradosExternos(vector <int> &grados,int gradosInternos, vector<int> &clique){
	int maximo = 0;
	for (unsigned int i = 0; i < clique.size(); i++) {
		int diferencia = grados[clique[i]] - gradosInternos;
		if (grados[clique[i]] > diferencia ) {
			maximo = maximo + diferencia;
		}
	}
	return maximo;
}

//O(size(clique)^2)
bool esClique(AdyMatrix& A, vector<int>& clique){
	for (unsigned int i = 0; i < clique.size(); i++) {
		for (unsigned int j = 0; j < clique.size(); j++) {
			if ( not(i == j ) ) {
				if (A.get(clique[i],clique[j]) == 0) {
					return false;
				}
			}
		}
	}
return true;
}

//O(size(cliques)*size(maxclique))
Solucion SolucionMaxima(vector <int> &grados,int k,list < vector < int > > cliques){
	Solucion sol;
	int max = 0;
	vector <int> maxclique;
	int internos = gradosInternos(k); //O(1)

	//O( size(cliques)* size(clique)  )
	for (std::list<vector <int > >::iterator it=cliques.begin(); it != cliques.end(); ++it){
		int externos = gradosExternos(grados,internos,*it); //O(size(clique))
		if (externos > max) {
			max = externos;
			maxclique = *it;
		}
	}
	sol.F = max;
	sol.k = k;
	sol.v = maxclique; //O(size(clique))
	return sol;
}

//O(size(conjunto)* (n^2) )
void EliminarNoCliques(AdyMatrix & A, list < vector <int > > &conjunto) {

	list< vector <int> >::iterator it = conjunto.begin();

	//O(size(conjunto)* (n) )
	while (it != conjunto.end()) {
		if (! esClique(A,*it)) { //O(size(it)^2) = O(size(maxclique)^2) = O(n^2)
			it = conjunto.erase(it); //O(1) por ser list
		}
		else{
			it++;
		}
	}
}

//O(1)
void saver(list < vector < int > > &hk, vector <int> &l) {
  hk.push_back(l);
}

/*
	Como se forman todas las posibles combinaciones de nodos de tamaño k , se tienen como mucho combinatorio(n,k) que es acotado por partes de A que tiene elementos 2^n entonces realiza como mucho 2^n iteraciones de tiempo consante cada una.
	O(1) + recursion = O((2^n)) y tiene (2^n) cantidad de elementos el vector donde se guardan las cliques
*/
void subset(vector<int> v, int size, int left, int index, vector<int> &l, list < vector < int > > &hk){
    if(left==0){
        saver(hk,l); //O(1)
        return;
    }

    //O(size - index)
    for(int i=index; i<size;i++){
        l.push_back(v[i]); //O(1)
        subset(v,size,left-1,i+1,l,hk); //O(1)
        l.pop_back(); //O(1)
    }
}


//O(n!*n^2)
Solucion SolucionExacta(AdyMatrix &M,int n,int m,int k) {
	vector < vector < int > > conjunto;
	vector <int> grados = Grados(M,n); //O(n^2)
	vector <int> vertices;

	//O(n)
	for (int i = 0; i < n; i++) {
		vertices.push_back(i);
	}

	list <vector <int > > cliques;
	vector<int> l;
	subset(vertices,vertices.size(),k,0,l,cliques); //O((2^n))
	EliminarNoCliques(M,cliques); //O((2^n)*n^2)
	Solucion sol = SolucionMaxima(grados,k,cliques); //O((2^n)*n^2) Asumiendo que no se borro ninguna clique
	return sol;
}


//O(2^n*n^3)
Solucion Ej1(AdyMatrix &M,int n,int m){
	Solucion max;
	max.F = 0;
	max.k = 0;
	int nodoMax = 0;
	std::vector<int> v = Grados(M,n); //(n^2)
	int Max1Clique = MaximoGrado(v,nodoMax); //O(n)

	//O(n*  ((2^n) *n^2) )
	for (int i = 2; i < n; i++) {
		Solucion sol;
		sol = SolucionExacta(M,n,m,i); //O((2^n) * n^2)
		if (max.F < sol.F) {
			max= sol;
		}
	}


	if (Max1Clique > max.F) { //O(1)
		std::vector<int> v;
		v.push_back(nodoMax);
		max.F = Max1Clique;
		max.k = 1;
		max.v = v;
	}

	return max;
}
