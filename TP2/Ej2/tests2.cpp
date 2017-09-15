#include "bfmod.h"
#include <utility>      // std::pair, std::make_pair
#include <stdlib.h>     /* srand, rand */

using namespace std;

vector<Arista> armarAristas(vector<vector<pair<int, int> > > &protoAristas)	//protoAristas es un diccionario, no es lo que uso en bfmod.
{
	vector<Arista> aristas;	
	for(int i = 0; i < (int)protoAristas.size(); i++)
	{
		for(int j = 0; j < (int)protoAristas[i].size(); j++)
		{
			Arista nuevaA(i,protoAristas[i][j].first +1, protoAristas[i][j].second +1);	//xq en el diccionario van de 0 a n-1, pero en el bfm van de 1 a n
			aristas.push_back(nuevaA);
		}
	}
	return aristas;
}
/*
void dameCiclo(int n, vector<vector<pair<int, int> > > &aristas, int nuevasA, int pmin, int pmax)
{
	srand(rand());
	int a = rand() % n;	//elijo un nodo inicial
	//vector<int> visitados;
	//visitados.push_back(a);

	int anterior = a;
	int b;
	for(int i = 0; i < nuevasA-1; i++)
	{
		bool distinto = true;
		do
		{
			distinto = true;
			b = rand() % (pmax-pmin) + pmin;
			if(b != a)
			{
				for(int j = 0; j < (int)aristas[anterior].size(); j++)
				{
					if(aristas[anterior][j].first == b)
						distinto = false;
				}
			}
			else
				distinto = false;

		}while(!distinto);

		aristas[anterior].push_back(make_pair(b,rand() % (pmax-pmin) + pmin));
	}

	aristas[anterior].push_back(make_pair(a,rand() % (pmax-pmin) + pmin));
}
*/
vector<Arista> crearGrafo(int n, int pmin, int pmax)
{
	//cout << "      inicio crearGrafo: " << endl;
	vector<vector<pair<int, int> > > protoAristas;
	srand(rand());
	int d;
	int m = n;
	for(int i = 0; i < m; i++)	//invariante
	{
		d = i;
		while(d == i)
			d = rand() % n;	//elijo un nodo destino

		vector<pair<int, int> > casiArista;
		protoAristas.push_back(casiArista);
		protoAristas[i].push_back(make_pair(d,rand() % (pmax-pmin) + pmin));
	}

	return armarAristas(protoAristas);
}

vector<Arista> crearGrafoConEjesRandoms(int n, int pmin, int pmax)
{
	//cout << "      inicio crearGrafo: " << endl;
	vector<vector<pair<int, int> > > protoAristas;
	srand(rand());
	int d;
	int m =  (rand() % (n*(n-1)/2)) + 1;
	for(int i = 0; i < n; i++)	//invariante
	{
		d = i;
		while(d == i)
			d = rand() % n;	//elijo un nodo destino

		vector<pair<int, int> > casiArista;
		protoAristas.push_back(casiArista);
		protoAristas[i].push_back(make_pair(d,rand() % (pmax-pmin) + pmin));
	}

	for(int i = 0; i < m-n; i++)	//invariante
	{
		d = i;
		while(d == i)
			d = rand() % n;	//elijo un nodo destino

		vector<pair<int, int> > casiArista;
		protoAristas.push_back(casiArista);
		protoAristas[i].push_back(make_pair(d,rand() % (pmax-pmin) + pmin));
	}

	return armarAristas(protoAristas);
}

vector<Arista> crearGrafoCompleto(int n, int pmin, int pmax)	//completo sin tener en cuenta las direcciones de las aristas
{
	srand(rand());
	int e,d;

	vector<vector<pair<int, int> > > protoAristas;

	for(int i = 0; i < n; i++)	//invariante
	{
		d = i;
		while(d == i)
			d = rand() % n;	//elijo un nodo destino

		vector<pair<int, int> > casiArista;
		protoAristas.push_back(casiArista);
		protoAristas[i].push_back(make_pair(d,rand() % (pmax-pmin) + pmin));
	}
/*
	for(int i = 0; i < n; i++)
	{
		cout << i << " --" << protoAristas[i][0].second << "-> " <<	 protoAristas[i][0].first << endl;
	}
*/
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(j != protoAristas[i][0].first && protoAristas[j][0].first != i)
			{
				e = rand() % 2;
				if(e)
					protoAristas[i].push_back(make_pair(j,rand() % (pmax-pmin) + pmin));
				else
					protoAristas[j].push_back(make_pair(i,rand() % (pmax-pmin) + pmin));
			}
		}
	}
	/*
	cout << "-----------" << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < protoAristas[i].size(); j++)
		{
			cout << i << " --" << protoAristas[i][j].second << "-> " << protoAristas[i][j].first << endl;
		}
	}*/

	return armarAristas(protoAristas);

}

void tiemposNN(int nmin, int nmax, int pmin, int pmax)	//vario N, M = 0, pmax y pmin fijos
{
	cout << "Grafo Minimo" << endl;
	int promedio;
	clock_t t_fin, t_ini;
	for(int i = nmin; i <= nmax; i++)
	{
		
		promedio = 0;
		int asize;
		//cout << "  i = " << i << endl;
		for(int rep = 0; rep < 50; rep++)
		{
			//cout << "    rep = " << rep << endl;
			vector<Arista> aristas = crearGrafo(i, pmin, pmax);
			asize = aristas.size();
			//cout << "      fin crearGrafo " << endl;

			t_ini = clock();
			ejercicio2(i,i, pmin, pmax, aristas);
			t_fin = clock();
			//cout << "    ej2 fin" << endl;
			promedio += (int) t_fin - (int) t_ini;
		}
		promedio /= 50;
		
		cout <<i<< " " << (double) promedio/1000 << endl;
	}
}

void tiemposC(int n, int pDifMin, int pDifMax)	//vario pmax y fijo pmin, N y M
{
	cout << "Variacion de C" << endl;
	int promedio;
	clock_t t_fin, t_ini;
	int pmin = 1;
	
	for(int pmax = pmin + pDifMin; pmax <= pmin + pDifMax; pmax+=5)
	{
		promedio = 0;
		//cout << "  pdif = " << pmax-1 << endl;
		for(int rep = 0; rep < 50; rep++)
		{
			//cout << "    rep = " << rep << endl;
			vector<Arista> aristas = crearGrafo(n, pmin, pmax);
			//cout << "      fin crearGrafo " << endl;
			t_ini = clock();
			ejercicio2(n,n, pmin, pmax, aristas);
			t_fin = clock();
			//cout << "    ej2 fin" << endl;
			promedio += (int)t_fin - (int)t_ini;
		}
		promedio /= 50;
		cout << pmax-1 << " " << (double) promedio/1000 << endl;
	}
}
	
void tiemposNMCompleto(int nmin, int nmax, int pmin, int pmax)	//vario N, M = grafo completo, pmax y pmin fijos
{
	cout << "Grafo Completo" << endl;
	int promedio;
	clock_t t_fin, t_ini;
	int asize;
	for(int i = nmin; i <= nmax; i++)
	{
		promedio = 0;
		for(int rep = 0; rep < 50; rep++)
		{
			vector<Arista> aristas = crearGrafoCompleto(i, pmin, pmax);
			asize = aristas.size();

			t_ini = clock();
			ejercicio2(i,asize, pmin, pmax, aristas);
			t_fin = clock();
			promedio += (int)t_fin - (int)t_ini;
		}
		promedio /= 50;
		cout << i << " " << (double) promedio/1000 << endl;
	}
}

void tiemposNMRandom(int nmin, int nmax, int pmin, int pmax)	
{
	cout << "Grafo Random" << endl;
	int promedio;
	clock_t t_fin, t_ini;
	int asize;
	for(int i = nmin; i <= nmax; i++)
	{
		promedio = 0;
		for(int rep = 0; rep < 50; rep++)
		{
			vector<Arista> aristas = crearGrafoConEjesRandoms(i, pmin, pmax);
			asize = aristas.size();

			t_ini = clock();
			ejercicio2(i,asize, pmin, pmax, aristas);
			t_fin = clock();
			promedio += (int)t_fin - (int)t_ini;
		}
		promedio /= 50;
		cout << i << " " << (double) promedio/1000 << endl;
	}
}

void correctitud()
{
	//cmin - cmax > 2
	int res;

	//ciclo simple de N nodos. FUNCIONA PARA TODO N TESTEADO
	vector<Arista> aristas2(200, Arista(1,2,1));
	//aristas2[0].print();
	for(int i = 1; i < (int)aristas2.size(); i++)
	{
		aristas2[i].origen = i+1;
		aristas2[i].destino = i+2;
		aristas2[i].peso = i+1;
		//aristas2[i].print();
	}
	aristas2[199].destino = 1;
	//aristas2[9].print();

	res = ejercicio2(200,200,1,200, aristas2);
	cout << "100 = " << res << endl;
}

int main()
{
	int min = 3;
	int max = 300;
	int pmin = 1;
	int pmax = 100;
	//correctitud();
	tiemposNMCompleto(min, max, pmin, pmax);
	tiemposNN(min, max, pmin,pmax);
	tiemposNMRandom(min, max, pmin, pmax);
	//tiemposC(150, 1, 500);

	return 0;
}
