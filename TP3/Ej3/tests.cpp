#include "heuristicaLocal.h"
#include "../Ej1/Exacto.h"
#include <time.h>
#include "../aux/Generadores/generador.h"

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
	for(int i = 4; i <= 25; i++)
	{
		cout << "n =  " << i << endl;
		for(int rep = 0; rep < 500; rep++)
		{
			//cout << "rep: " << rep << endl;
			clock_t extra = clock();
			srand(time(NULL)*(double)extra);
			//srand(rand());
			//1. crear grafo
			AdyMatrix A(i);

			int w = i*(i-1);
			w /= 2;

			w -= i;
			int m = rand() % w + i;

			//a. algo conexo, como en el tp2

			for(int x = 0; x < i; x++)
			{
				int y;
				do{
					y = rand() % i;
				}while(y == x);

				A.addEdge(x,y);
			}
			//b. el resto, todo random
			for(int x = i; x <= m; x++)
			{
				int x2,y;
				do{
					x2 = rand() % i;
					y = rand() % i;
				}while(y == x2);

				A.addEdge(x2,y);
			}

			//2. test

			//A.print();
			Solucion res = Ej1(A,i,m);
			int exactoF = res.F;
			res = hGolosa(A, i);
			if(exactoF < res.F) //tmb deberia mirar que si el goloso sale peor que el exacto, la clique del goloso no este incluida en la del exacto (xq eso seria un error del algoritmo)
				cout << "Algo salio muy mal (Goloso)" << endl;
			int golosoF = res.F;
			//cout << "antes de local" << endl;
			res = hLocal(A,res,i);
			if(golosoF > res.F || res.F > exactoF)
				cout << "Algo salio muy mal (Local): local es " << res.F << "; goloso es " << golosoF << "exacto es " << exactoF << endl;

			if(golosoF < res.F)
				cout << "Local mejora sol de goloso" << endl;

			if(exactoF > res.F)
				cout << "Local peor que el exacto" << endl;


		}
	}
}

void analisisAleatorio()
{

	int rep = 500;
	cout << "#analisisAleatorio ej3" << endl;
	cout << "#N promGL promLE maxGL maxLE ptG+L ptE" << endl;

	for(int i = 9; i <= 22; i++)
	{
		int maxGL = 0, maxLE = 0, mejoragl = 0, mejorale = 0;
		double promGL = 0, promLE = 0;

		double ptG = 0, ptL = 0, ptE2 = 0, tE = 0;
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

			ptL -= (double)clock();
			res = hLocal(A,res,i);
			ptL += (double)clock();
			int fl = res.F;

			if(fl > fg)
			{
				promGL += (fl - fg);
				maxGL = max(maxGL, fl - fg);
				mejoragl++;
			}
			if(fe > fl)
			{
				promLE += (fe - fl);
				maxLE = max(maxLE, fe - fl);
				mejorale++;
				}

		}

		promGL = (mejoragl > 0) ? round(promGL/mejoragl) : 0;
		promLE = (mejorale > 0) ? round(promLE/mejorale) : 0;

		ptG /= rep;
		ptL /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);
		ptE2 = round(ptE2 / 1000);

		cout << i << " " << promGL << " " << promLE << " " << maxGL << " " << maxLE << " " << ptG+ptL << " " << ptE2 << endl;
	}
}

void mejoraMalo()
{

	int rep = 100, m = -1, fe;
	cout << "#analisisMalo ej3" << endl;
	cout << "# N M promGL promLE maxGL maxLE ptG+L" << endl;
	double fe2;

	int n = -1;
	for(int i = 4; i <= 80; i++)
	{
		int maxGL = 0, maxLE = 0;
		double promGL = 0, promLE = 0;

		double ptG = 0, ptL = 0;
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
			int fg = res.F;

			ptL -= (double)clock();
			res = hLocal(A,res,n);
			ptL += (double)clock();
			int fl = res.F;

			promGL += (fl - fg);
			promLE += (fe - fl);

			maxGL = max(maxGL, fl - fg);
			maxLE = max(maxLE, fe - fl);
		}

		promGL = round(promGL/rep);
		promLE = round(promLE/rep);

		ptG /= rep;
		ptL /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);

		cout << n << " " << m << " " << promGL << " " << promLE << " " << maxGL << " " << maxLE << " " << ptG+ptL << endl;
	}
}

void mejoraAleatorio()
{

	int rep = 500;
	cout << "#mejoraAleatorio ej3" << endl;
	cout << "#N promGL maxGL ptG+L" << endl;

	for(int i = 10; i <= 500; i+=10)
	{
		int maxGL = 0, mejora = 0;
		double promGL = 0;

		double ptG = 0, ptL = 0;
		for(int r = 0; r < rep; r++)
		{
			int m;
			AdyMatrix A = crearGrafoAleatorio(i, m);

			//2. test

			Solucion res;

			ptG -= (double)clock();
			res = hGolosa(A, i);
			ptG += (double)clock();
			int fg = res.F;

			ptL -= (double)clock();
			res = hLocal(A,res,i);
			ptL += (double)clock();
			int fl = res.F;

			if(fl > fg)
			{
				promGL += (fl - fg);
				maxGL = max(maxGL, fl - fg);
				mejora++;
			}
		}

		promGL = (mejora > 0) ? round(promGL/mejora) : 0;

		ptG /= rep;
		ptL /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);

		cout << i << " " << promGL << " " << maxGL << " " << ptG + ptL << endl;
	}
}

int main()
{


	//test que corrobora la correctitud de los algoritmos comparandolo con el exacto
	// correctitud();


	//tests de algoritmo goloso y local utilizando el grafo contraejemplo para instancias mucho mas grandes
	//de las que se pueden evaluar comparado con el exacto
	// mejoraMalo();

	// test de grafos aleatorios  comparandose contra el algoritmo exacto
	// analisisAleatorio();

	//tests de grafos aleatorios SIN compararse con el algoritmo exacto
	mejoraAleatorio();

	return 0;
}
