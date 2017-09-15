#include "tabu.h"

Solucion hGolosa2(AdyMatrix& Modif, AdyMatrix& Full, int n, vector<int>& tabuList)
{
	/*
		Uso Modif para crear la clique, y Full para recorrer y calcular la frontera
	*/

	Solucion s;
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
			if(Full(i,j) == 1)
				gr++;
		}
		grados[gr].push_back(i);
	}

	int maxF = 0;
	vector<int> maxClique;
	for(int e = 0; e < n; e++)
	{
		bool a = true;
		for(int i = 0; i < (int)tabuList.size(); i++)
			if(tabuList[i] == e)
				a = false;
		if(a)
		{
			vector<int> clique;
			clique.push_back(e);
			int F = grado(Full,e);

			for(int gr_v = n-1; gr_v >= (int)clique.size(); gr_v--)	//los nodos originales ordenados por grado, para dar mejor resultado.
			{
				//gr_v >= n es lo minimo que hay q pedir para AGREGAR en la clique
				for(int v = 0; v < (int)grados[gr_v].size(); v++)	//for(cada nodo con el grado gr_v) (los 2 for forman O(N))
				{
					a = true;
					for(int i = 0; i < (int)tabuList.size(); i++)
						if(tabuList[i] == grados[gr_v][v])
							a = false;
					if(a)
					{
						if(esClique(Modif, clique, grados[gr_v][v]))	//los elementos quitados daran False
						{
							if(F < F + gr_v - 2*(int)clique.size())	//y si tiene una frontera mas grande
							{
								F = F + gr_v - 2*(int)clique.size();
								clique.push_back(grados[gr_v][v]);
							}
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
	}
	
	s.F = maxF;
	s.k = maxClique.size();
	s.v = maxClique;

	return s;
}

void nodo2tabuList(AdyMatrix& A, AdyMatrix& B, vector<int>& v, vector<int>& tabuList, int& pos, int k)
{	
	int p = v[0];
	//ahora lo agrego a la lista tabu, lo quito de B y agrego algun nodo a B si es necesario.
	B.removeNode(p);
	if((int)tabuList.size() >= k)
	{
		B.add(A, tabuList[pos]);
		tabuList[pos] = p;
		pos++;
		if(pos >= k) pos = 0;
	}
	else
		tabuList.push_back(p);
}

Solucion hTabu(AdyMatrix& A, int n, int k, int& maxRep)
{
	/**
		Algoritmo tabu:
			1) Llamo al algoritmo goloso con la AdyMatrix que necesito.	O(n^3)
			2) Llamo al algoritmo de Busqueda Local con la AdyMatrix original. O(n^3)
			3) Quito las aristas de la solucion de Busqueda Local. O(n^2)
			4) Repeat. Hasta que no mejore x 20 rondas. O(convergencia)
	*/

	AdyMatrix B(A);
	Solucion s;
	vector<int> tabuList;
	int sinMejorar = 0;
	int vecesMejoro = -1;
	maxRep = 0;
	Solucion mejorS;
	mejorS.F = 0;
	int r = 0;	//elemento que reemplpazo de la lista tabu para hacer una "lista ciclica"

	do{
		s = hGolosa2(B, A, n, tabuList);
		//cout << s << endl;
		
		nodo2tabuList(A, B, s.v, tabuList, r, k);

		s = hLocal(A, s, n);



		if(mejorS.F < s.F)
		{
			if(vecesMejoro > -1)
			{
				if(sinMejorar > maxRep)
					maxRep = sinMejorar;
			}
			mejorS = s;
			
			sinMejorar = 0;
			vecesMejoro++;
		}
		else
			sinMejorar++;

	}while(sinMejorar < n);

	return mejorS;
}

Solucion hTabu1(AdyMatrix& A, int n, int k, int& maxRep)	
{
	//k va a ser el tamaño maximo de la tabulist
	
	//Busco maximisar sol.F y reducir k, vecesMejoro y maxRep
	//minRep es principalmente estadistico, me interesa mucho mas maxRep
	
	/**
		Algoritmo tabu:
			1) Llamo al algoritmo goloso con la AdyMatrix que necesito.	O(n^3)
			2) Llamo al algoritmo de Busqueda Local con la AdyMatrix original. O(n^3)
			3) Quito las aristas de la solucion de Busqueda Local. O(n^2)
			4) Repeat. Hasta que no mejore x 20 rondas. O(convergencia)
	*/

	// 1)
	AdyMatrix B(A);
	Solucion s;
	//int prevF;
	vector<vector<int> > tabuList;
	int sinMejorar = 0;
	int vecesMejoro = -1;
	maxRep = 0;
	Solucion mejorS;
	mejorS.F = 0;
	int r = 0;	//elemento que reemplpazo de la lista tabu para hacer una "lista ciclica"

	do{
		vector<int> l;
		s = hGolosa2(B, A, n, l);
		
		s = hLocal(A, s, n);

		B.erase(s.v);	//erase quita las aristas de s.v
		if((int)tabuList.size() >= k)
		{
			B.add(tabuList[r]);
			tabuList[r] = s.v;
			r++;
			if(r >= k) r = 0;
		}
		else
			tabuList.push_back(s.v);

		if(mejorS.F < s.F)
		{
			if(vecesMejoro > -1)
			{
				if(sinMejorar > maxRep)
					maxRep = sinMejorar;
			}
			mejorS = s;
			
			sinMejorar = 0;
			vecesMejoro++;
		}
		else
			sinMejorar++;
	}while(sinMejorar < n);

	return mejorS;
}

void nodo2tabuListMenor(AdyMatrix& A, AdyMatrix& B, vector<int>& v, vector<int>& tabuList, int& pos, int k)
{	
	//k va a ser el tamaño maximo de la tabulist

	int g = 0, p = 0, minD = B.size();
	for(int i = 0; i < (int)v.size(); i++)
	{
		g = grado(B,i);
		if(g < minD)
		{
			p = i;
			minD = g;
		}
	}
	
	//ahora lo agrego a la lista tabu, lo quito de B y agrego algun nodo a B si es necesario.
	B.removeNode(p);
	if((int)tabuList.size() >= k)
	{
		B.add(A, tabuList[pos]);
		tabuList[pos] = p;
		pos++;
		if(pos >= k) pos = 0;
	}
	else
		tabuList.push_back(p);
}

void nodo2tabuListMayor(AdyMatrix& A, AdyMatrix& B, vector<int>& v, vector<int>& tabuList, int& pos, int k)
{	
	//k va a ser el tamaño maximo de la tabulist

	int g = 0, p = 0, maxD = 0;
	for(int i = 0; i < (int)v.size(); i++)
	{
		g = grado(B,i);
		if(g > maxD)
		{
			p = i;
			maxD = g;
		}
	}
	
	//ahora lo agrego a la lista tabu, lo quito de B y agrego algun nodo a B si es necesario.
	B.removeNode(p);
	if((int)tabuList.size() >= k)
	{
		B.add(A, tabuList[pos]);
		tabuList[pos] = p;
		pos++;
		if(pos >= k) pos = 0;
	}
	else
		tabuList.push_back(p);
}

void nodo2tabuListRand(AdyMatrix& A, AdyMatrix& B, vector<int>& v, vector<int>& tabuList, int& pos, int k)
{	
	//k va a ser el tamaño maximo de la tabulist
	clock_t extra = clock();
	srand(time(NULL)*(double)extra);
	int p = rand() % v.size();
	
	//ahora lo agrego a la lista tabu, lo quito de B y agrego algun nodo a B si es necesario.
	B.removeNode(p);
	if((int)tabuList.size() >= k)
	{
		B.add(A, tabuList[pos]);
		tabuList[pos] = p;
		pos++;
		if(pos >= k) pos = 0;
	}
	else
		tabuList.push_back(p);
}

Solucion hTabu2(AdyMatrix& A, int n, int k, int& maxRep)
{
	/**
		Algoritmo tabu:
			1) Llamo al algoritmo goloso con la AdyMatrix que necesito.	O(n^3)
			2) Llamo al algoritmo de Busqueda Local con la AdyMatrix original. O(n^3)
			3) Quito las aristas de la solucion de Busqueda Local. O(n^2)
			4) Repeat. Hasta que no mejore x 20 rondas. O(convergencia)
	*/

	// 1)
	AdyMatrix B(A);
	Solucion s;
	//int prevF;
	vector<int> tabuList;
	int sinMejorar = 0;
	int vecesMejoro = -1;
	maxRep = 0;
	Solucion mejorS;
	mejorS.F = 0;
	//int k = 4;	//k va a ser el tamaño maximo de la tabulist
	int r = 0;	//elemento que reemplpazo de la lista tabu para hacer una "lista ciclica"

	do{
		s = hGolosa2(B, A, n, tabuList);
		
		s = hLocal(A, s, n);

		//B = A.remove(s.v);	//remove no modifica A, arma un nuevo objeto Solucion sin las aristas de s.v

		/**
			Dif: en este tabu tomo el nodo de menor grado y solo quito ese
		*/

		nodo2tabuList(A, B, s.v, tabuList, r, k);

		if(mejorS.F < s.F)
		{
			if(vecesMejoro > -1)
			{
				if(sinMejorar > maxRep)
					maxRep = sinMejorar;
			}
			mejorS = s;
			
			sinMejorar = 0;
			vecesMejoro++;
		}
		else
			sinMejorar++;

	}while(sinMejorar < n);

	return mejorS;
}

Solucion hTabu3(AdyMatrix& A, int n, int k, int& maxRep, int n2t)
{
	/**
		Algoritmo tabu:
			1) Llamo al algoritmo goloso con la AdyMatrix que necesito.	O(n^3)
			2) Llamo al algoritmo de Busqueda Local con la AdyMatrix original. O(n^3)
			3) Quito las aristas de la solucion de Busqueda Local. O(n^2)
			4) Repeat. Hasta que no mejore x 20 rondas. O(convergencia)
	*/

	// 1)
	AdyMatrix B(A);
	Solucion s;
	//int prevF;
	vector<int> tabuList;
	int sinMejorar = 0;
	int vecesMejoro = -1;
	maxRep = 0;
	Solucion mejorS;
	mejorS.F = 0;
	int r = 0;	//elemento que reemplpazo de la lista tabu para hacer una "lista ciclica"

	do{
		s = hGolosa2(B, A, n, tabuList);
		
		s = hLocal(A, s, n);

		switch(n2t)
		{
			case 0: 
				nodo2tabuList(A, B, s.v, tabuList, r, k);
				break;
			case 1: 
				nodo2tabuListMenor(A, B, s.v, tabuList, r, k);
				break;
			case 2: 
				nodo2tabuListMayor(A, B, s.v, tabuList, r, k);
				break;
			case 3: 
				nodo2tabuListRand(A, B, s.v, tabuList, r, k);
				break;
		}

		if(mejorS.F < s.F)
		{
			if(vecesMejoro > -1)
			{
				if(sinMejorar > maxRep)
					maxRep = sinMejorar;
			}
			mejorS = s;
			
			sinMejorar = 0;
			vecesMejoro++;
		}
		else
			sinMejorar++;

	}while(sinMejorar < n);

	return mejorS;
}