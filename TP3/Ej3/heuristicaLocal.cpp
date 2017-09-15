#include "heuristicaLocal.h"


Solucion hLocal(AdyMatrix& A, Solucion& sol, int n)
{
	/**
		Algoritmo de Busqueda Local:
			1) Obtengo los nodos ordenados por grado. O(n)
			2) Swapeo nodos para dar una solucion nueva. O(n^2) * O(esClique) = O(n^3)
			3) Verifico si no puedo agregar mas nodos. O(n^3)

			
	*/

	Solucion res;

	// 1)
	//cout << "(1)" << endl;
	//cout << sol << endl;

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
			if((i != j) && A(min(i,j), max(i,j)) == 1)
				gr++;
		}
		grados[gr].push_back(i);
	}
	int maxF = sol.F, prevF;
	vector<int> maxClique = sol.v;
	int auxF = sol.F;
	vector<int> cliqueAux = sol.v;

	do
	{
		prevF = maxF;
		// (!) Cada iteracion solo quita 1 nodo de la sol original 

		for(int i = 0; i < sol.k; i++)	//x cada nodo de la solucion, pruebo swapear
		{
			int e = sol.v[i];	
			for(int gr_v = n-1; gr_v >= sol.k-1; gr_v--)	//los nodos originales ordenados por grado, para dar mejor resultado.
			{
				//gr_v >= n-1 es lo minimo que hay q pedir para REEMPLAZAR en la clique
				for(int v = 0; v < (int)grados[gr_v].size(); v++)	//for(cada nodo con el grado gr_v) (los 2 for forman O(N))
				{
					if(esClique(A, sol.v, grados[gr_v][v], e))	//esClique tmb verifica si hay repetidos
					{
						int gr_e = grado(A,e);
						if(sol.F < (sol.F - gr_e) + gr_v)	//y si tiene una frontera mas grande.. 
						{
							auxF = sol.F - gr_e + gr_v;
							cliqueAux = sol.v;
							cliqueAux[i] = grados[gr_v][v];
							for(int gr_p = n-1; gr_p >= (int)cliqueAux.size(); gr_p--)	//los nodos originales ordenados por grado, para dar mejor resultado.
							{
								//gr_p >= n es lo minimo que hay q pedir para AGREGAR en la clique
								for(int p = 0; p < (int)grados[gr_p].size(); p++)	//for(cada nodo con el grado gr_p) (los 2 for forman O(N))
								{
									if(esClique(A, cliqueAux, grados[gr_p][p]))	//esClique tmb verifica si hay repetidos
									{
										if(auxF < auxF + gr_p - 2*(int)cliqueAux.size())	//y si tiene una frontera mas grande.. 
										{
											auxF = auxF + gr_p - 2*(int)cliqueAux.size();
											cliqueAux.push_back(grados[gr_p][p]);
										}
									}
								}
							}
							if(auxF > maxF)
							{
								maxF = auxF;
								maxClique = cliqueAux;
							}
						}
					}
				}
			}
		}
	}while(prevF < maxF);



	res.F = maxF;
	res.k = maxClique.size();
	res.v = maxClique;

	//cout << res << endl;

	return res;
}

bool esClique(AdyMatrix& A, vector<int>& clique, int v, int ignore)
{
	for(int i = 0; i < (int)clique.size(); i++)
	{
		if((clique[i] != ignore) && A(min(clique[i],v), max(clique[i],v)) != 1)
			return false;
	}
	return true;
}