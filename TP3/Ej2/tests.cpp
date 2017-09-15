#include "heuristicaGolosa.h"
#include "../Ej1/Exacto.h"
#include <time.h>
#include "../aux/Generadores/generador.h"
#include <chrono>
#define ya chrono::high_resolution_clock::now


AdyMatrix crearGrafoAleatorio(int n, int& m)
{
	clock_t extra = clock();
	srand(time(NULL)*(double)extra);
	//1. crear grafo
	AdyMatrix A(n);

	int w = n*(n-1);
	w /= 2;

	w -= n;
	m = rand() % w + n;

	//a. algo conexo, como en el tp2

	for(int x = 0; x < n; x++)
	{
		int y;
		do{
			y = rand() % n;
		}while(y == x);

		A.addEdge(x,y);
	}
	//b. el resto, todo random
	for(int x = n; x <= m; x++)
	{
		int x2,y;
		do{
			x2 = rand() % n;
			y = rand() % n;
		}while(y == x2);

		A.addEdge(x2,y);
	}
	return A;
}

void correctitud()
{
	//1) Grafo estrella: el resultado es la clique del nodo central unicamente. F = n-1
	//2) Grafo completo: k = n/2 (floor y ceil valen), F= floor(double(n/2)^2)
	//3) Bipartito completo Kpq: k = 2, F = p+q-2
	//4) Ciclo con n > 2: k = 2, F = 2
	//5) Camino con n > 3: k = 2, F = 2; con n = 3: k = 1, F = 2
	//6) Arbol binario balanceado con h >= 3 (h=0 es el grafo trivial): k = 2, F = 4
	//6b) Arbol binario balanceado y h = 2: k = 2 y F = 3
	//6c) Arbol binario balanceado y h = 1: P3 (k = 1 y F = 2)

	for(int n = 4; n <= 200; n++)
	{
		//cout << n << ": " << endl;
		//1)
		AdyMatrix M(n);

		for(int i = 1 ; i < n; i++)
		{
			M.addEdge(0,i);
		}

		Solucion res = hGolosa(M, n);

		if(res.k != 1 || res.F != n-1)
			cout << "Grafo estrella: fail. F=" << res.F << " & k=" << res.k << ")" << endl;

		//2)
		AdyMatrix M2(n);

		for(int i = 0 ; i < n-1; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				M2.addEdge(i,j);
			}
		}

		Solucion res2 = hGolosa(M2, n);

		double ene = (double)n;
		double efe = floor(pow(ene/2, 2));

		if(res2.k != n/2 || (double)res2.F != efe)
		{
			cout << "Grafo completo: fail" << endl;
			cout << "k = " << n/2 << " = " << res2.k << " , F = " << efe << " = " << res2.F << endl;
		}
	}
}

void analisisAleatorio()
{

	int rep = 500;
	cout << "#analisisAleatorio" << endl;
	cout << "#N promGE(con F(G)!=F(E)) maxGE tG ptE2" << endl;

	for(int i = 9; i <= 22; i++)
	{
		int maxGE = 0, mejoras = 0;
		double promGE = 0;

		double ptG = 0, ptE2 = 0, tE = 0;
		for(int r = 0; r < rep; r++)
		{
			int m;
			AdyMatrix A = crearGrafoAleatorio(i, m);

			//2. test

			//A.print();
			tE = (double)clock();
			Solucion res = Ej1(A,i,m);
			tE = (double)clock() - tE;
			ptE2 += tE/rep;
			int fe = res.F;

			ptG -= (double)clock();
			res = hGolosa(A, i);
			ptG += (double)clock();
			int fg = res.F;
			if (fe > fg)
			{
				promGE += (fe - fg);
				mejoras++;
				maxGE = max(maxGE, fe - fg);
			}
		}

		promGE = (mejoras > 0) ? round(promGE/mejoras) : 0;

		ptG /= rep;

		ptG = round(ptG / 1000);
		ptE2 = round(ptE2 / 1000);

		cout << i << " " << promGE << " " << maxGE << " " << ptG << " " << ptE2 << endl;
	}
}

void analisisMalo()
{

	int rep = 100, fe,fg;
	double fe2;
	cout << "#analisisMalo" << endl;
	cout << "#N M promGE maxGE tG" << endl;
	int n = -1, m = -1;

	for(int i = 5; i <= 80; i++)
	{
		int maxGE = 0, mejoras = 0;
		double promGE = 0;

		double ptG = 0;
		for(int r = 0; r < rep; r++)
		{
			AdyMatrix A = createBadGraphForGreedy(i);
			n = A.size();
			m = A.aristas2();
			double ene = (double)i;
			double efe = floor(pow(ene/2, 2));

			//A.print();
			Solucion res;
			fe2 = efe + floor(i/2);
			fe = (int)fe2;


			ptG -= (double)clock();
			res = hGolosa(A, n);
			ptG += (double)clock();
			fg = res.F;

			if (fe > fg)
			{
				promGE += (fe - fg);
				mejoras++;
				maxGE = max(maxGE, fe - fg);
			}
		}

		promGE = round(promGE/rep);

		ptG /= rep;

		ptG = round(ptG / 1000);

		cout << n << " " << m << " " << promGE << " " << maxGE << " " << ptG << endl;
	}
}






void Pearson_Goloso(int Tam, int repeticiones,int salto) {
	for (int i = 1; i < Tam; i++) {
		std::cout << "tamaño: " <<i*salto <<'\n';
		int tamanio = i*salto;
		int m;
		AdyMatrix A = crearGrafoAleatorio(tamanio, m);
		for (int j = 0; j < repeticiones; j++) {
			auto start = ya();
			Solucion sol = hGolosa(A,tamanio);
			auto end = ya();
			cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
		}

	}
}

void call_pearsonGoloso() {
	int tamanio = 100;
	int repeticiones = 10;
	int salto = 5;
	Pearson_Goloso(tamanio,repeticiones,salto);
}


int main(){

	// tests para corroborar la correctitud del programa
	// correctitud();

	//test de casos aleatorios para la heurística golosa
	// analisisAleatorio();

	// test para la heurística golosa en donde la entrada es el caso en donde falla
	// analisisMalo();

	//tests de tiempo para calculo del coeficiente de pearson
	call_pearsonGoloso();
	return 0;
}
