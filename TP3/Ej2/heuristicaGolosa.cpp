#include "heuristicaGolosa.h"


Solucion hGolosa(AdyMatrix& A, int n)
{
	/**
		Algoritmo goloso:
			1) ordeno los nodos segun el grado
			2) tomo un nodo de mayor a menor grado y le voy agregando nodos siempre y cuando formen una clique (y aumente la frontera)
			3) repetir arrancando de distintos nodos

			Complejidad temporal: inicio + n (cada nodo de inicio)* n(cada nodo a agregar)*verificarClique = O(n^3)
			O(inicio) = O(n^2)
			O(verificarClique) = O(n)
	*/

	Solucion s;

	// 1)

	vector<vector<int> > grados;

	for(int i = 0; i < n; i++)
	{
		vector<int> aux;
		grados.push_back(aux);
	}

	for(int i = 0; i < n; i++)
	{
		int gr = 0;
		for(int j = 0; j < n; j++)
		{
			if(A(i,j) == 1)
				gr++;
		}
		grados[gr].push_back(i);
	}

	//2 y 3)

	int maxF = 0;
	vector<int> maxClique;
	for(int e = 0; e < n; e++)	//3)
	{
		vector<int> clique;
		clique.push_back(e);
		int F = grado(A,e);

		for(int gr_v = n-1; gr_v >= (int)clique.size(); gr_v--)	//los nodos originales ordenados por grado, para dar mejor resultado.
		{
			//gr_v >= n es lo minimo que hay q pedir para AGREGAR en la clique
			for(int v = 0; v < (int)grados[gr_v].size(); v++)	//for(cada nodo con el grado gr_v) (los 2 for forman O(N))
			{
				if(esClique(A, clique, grados[gr_v][v]))
				{
					if(F < F + gr_v - 2*(int)clique.size())	//y si tiene una frontera mas grande
					{
						F = F + gr_v - 2*(int)clique.size();
						clique.push_back(grados[gr_v][v]);
					}
				}
			}
		}
		if(maxF < F)
		{
			maxF = F;
			maxClique = clique;
		}
	}

	
	s.F = maxF;
	s.k = maxClique.size();
	s.v = maxClique;

	return s;
}

bool esClique(AdyMatrix& A, vector<int>& clique, int v)
{
	for(int i = 0; i < (int)clique.size(); i++)
	{
		if(A(min(clique[i],v), max(clique[i],v)) != 1)
			return false;
	}
	return true;
}

int grado(AdyMatrix& A, int v)
{
	int g = 0;
	for(int i = 0; i < A.size(); i++)
	{
		g += A(i,v);
	}

	return g;
}