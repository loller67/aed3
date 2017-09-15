#include "tabu.h"
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

void analisisAleatorio()
{

	int rep = 500;
	cout << "#analisisAleatorio ej4" << endl;
	cout << "#N promGL promLT promTE maxGL maxLT maxTE ptG+L ptT ptE" << endl;

	for(int i = 9; i <= 22; i++)
	{
		int maxGL = 0, maxLT = 0, maxTE = 0, mejoragl = 0, mejoralt = 0, mejorate = 0;
		double promGL = 0, promLT = 0, promTE = 0;

		double ptG = 0, ptL= 0, ptT = 0, ptE2 = 0, tE = 0;
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

			int q = 0;
			ptT -= (double)clock();
			res = hTabu(A, i, i/3, q);
			ptT += (double)clock();
			int ft = res.F;

			if(fl > fg)
			{
				promGL += (fl - fg);
				maxGL = max(maxGL, fl - fg);
				mejoragl++;
			}
			if(ft > fl)
			{
				promLT += (ft - fl);
				maxLT = max(maxLT, ft - fl);
				mejoralt++;
			}

			if(fe > ft)
			{
				promTE += (fe - ft);
				maxTE = max(maxTE, fe - ft);
				mejorate++;
			}
		}

		promGL = (mejoragl > 0) ? round(promGL/mejoragl) : 0;
		promLT = (mejoralt > 0) ? round(promLT/mejoralt) : 0;
		promTE = (mejorate > 0) ? round(promTE/mejorate) : 0;

		ptG /= rep;
		ptL /= rep;
		ptT /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);
		ptT = round(ptT / 1000);
		ptE2 = round(ptE2 / 1000);

		cout << i << " " << promGL << " " << promLT << " " << promTE << " " << maxGL << " " << maxLT << " " << maxTE << " " << ptG+ptL << " " << ptT << " " << ptE2 << endl;
	}
}

void analisisKRegular()
{

	int rep = 50;
	cout << "#analisisKRegular ej4" << endl;
	cout << "#N promGL promLT promTE maxGL maxLT maxTE ptG+L ptT ptE" << endl;

	for(int i = 9; i <= 22; i++)
	{
		int maxGL = 0, maxLT = 0, maxTE = 0, mejoragl = 0, mejoralt = 0, mejorate = 0;
		double promGL = 0, promLT = 0, promTE = 0;

		double ptG = 0, ptL= 0, ptT = 0, ptE2 = 0, tE = 0;
		for(int r = 0; r < rep; r++)
		{
			int m = -1;
			int k = 4;
			AdyMatrix A = createKRegularRandomGraph(k, i);

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

			int q = 0;
			ptT -= (double)clock();
			res = hTabu(A, i, i/3, q);
			ptT += (double)clock();
			int ft = res.F;

			if(fl > fg)
			{
				promGL += (fl - fg);
				maxGL = max(maxGL, fl - fg);
				mejoragl++;
			}
			if(ft > fl)
			{
				promLT += (ft - fl);
				maxLT = max(maxLT, ft - fl);
				mejoralt++;
			}

			if(fe > ft)
			{
				promTE += (fe - ft);
				maxTE = max(maxTE, fe - ft);
				mejorate++;
			}
		}

		promGL = (mejoragl > 0) ? round(promGL/mejoragl) : 0;
		promLT = (mejoralt > 0) ? round(promLT/mejoralt) : 0;
		promTE = (mejorate > 0) ? round(promTE/mejorate) : 0;

		ptG /= rep;
		ptL /= rep;
		ptT /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);
		ptT = round(ptT / 1000);
		ptE2 = round(ptE2 / 1000);

		cout << i << " " << promGL << " " << promLT << " " << promTE << " " << maxGL << " " << maxLT << " " << maxTE << " " << ptG+ptL << " " << ptT << " " << ptE2 << endl;
	}
}

void mejoraMalo()
{

	int rep = 1, m = -1;
	cout << "#mejoraMalo ej4" << endl;
	cout << "# N M promGL promLT promTE maxGL maxLT maxTE ptG+L ptT" << endl;
	double fe2;

	int n = -1;
	for(int i = 6; i <= 50; i++)
	{
		int maxGL = 0, maxLT = 0, maxTE = 0;
		double promGL = 0, promLT = 0, promTE = 0;

		int fg = 0, fl = 0, ft = 0, fe = 0;
		double ptG = 0, ptL = 0, ptT = 0;
		for(int r = 0; r < rep; r++)
		{
			Solucion res;
			AdyMatrix A = createBadGraphForGreedy(i);
			n = A.size();
			m = A.aristas2();

			double ene = (double)i;
			double fe2 = (ceil(ene/2) * floor(ene/2) )+ ceil(ene/2);
			fe = (int)fe2;

			ptG -= (double)clock();
			res = hGolosa(A, n);
			ptG += (double)clock();
			fg = res.F;

			ptL -= (double)clock();
			res = hLocal(A,res,n);
			ptL += (double)clock();
			fl = res.F;

			int q = 0;
			ptT -= (double)clock();
			res = hTabu(A,n, n/3, q);
			ptT += (double)clock();
			ft = res.F;
			//cout << res << endl;

			promGL += (fl - fg);
			promLT += (ft - fl);
			promTE += (fe - ft);

			maxGL = max(maxGL, fl - fg);
			maxLT = max(maxLT, ft - fl);
			maxTE = max(maxTE, fe - ft);
		}

		promGL = round(promGL/rep);
		promLT = round(promLT/rep);
		promTE = round(promTE/rep);

		ptG /= rep;
		ptL /= rep;
		ptT /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);
		ptT = round(ptT / 1000);

		//cout << n << " " << m << " " << promGL << " " << promLT << " " << promTE << " " << maxGL << " " << maxLT << " " << maxTE << " " << ptG+ptL << " " <<  ptT << endl;
		cout << n << " " << fg << " " << fl << " " << ft << " " << fe << endl;
	}
}

void mejoraAleatorio()
{

	int rep = 500;
	cout << "#mejoraAleatorio ej4" << endl;
	cout << "#N promGL promLT maxGL maxLT ptG+L ptT" << endl;

	for(int i = 10; i <= 200; i+=10)
	{
		int maxGL = 0, maxLT = 0, mejoragl = 0, mejoralt = 0;
		double promGL = 0, promLT = 0;

		double ptG = 0, ptL= 0, ptT = 0;
		for(int r = 0; r < rep; r++)
		{
			int m;
			AdyMatrix A = crearGrafoAleatorio(i, m);

			Solucion res;

			ptG -= (double)clock();
			res = hGolosa(A, i);
			ptG += (double)clock();
			int fg = res.F;

			ptL -= (double)clock();
			res = hLocal(A,res,i);
			ptL += (double)clock();
			int fl = res.F;

			int q = 0;
			ptT -= (double)clock();
			res = hTabu(A,i, i/3, q);
			ptT += (double)clock();
			int ft = res.F;

			if(fl > fg)
			{
				promGL += (fl - fg);
				maxGL = max(maxGL, fl - fg);
				mejoragl++;
			}
			if(ft > fl)
			{
				promLT += (ft - fl);
				maxLT = max(maxLT, ft - fl);
				mejoralt++;
			}
		}

		promGL = (mejoragl > 0) ? round(promGL/mejoragl) : 0;
		promLT = (mejoralt > 0) ? round(promLT/mejoralt) : 0;

		ptG /= rep;
		ptL /= rep;
		ptT /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);
		ptT = round(ptT / 1000);

		cout << i << " " << promGL << " " << promLT << " " << maxGL << " " << maxLT << " " << ptG+ptL << " " << ptT << endl;
	}
}


void testTabus()
{
	int maxRep, max1, max2, maxF1, maxF2, maxk1, maxk2;
	int n, vecesT1mejor = 0, vecesT2mejor = 0;

	double promT1mejor = 0, promT2mejor = 0;

	cout << "# N veces_T1_mejor prom_T1_mejora veces_T2_mejor prom_T2_mejora" << endl;

	//for(int n = 10; n <= 40; n+=5)
	for(int i = 5; i <= 10; i++)
	{
		max1 = -1;
		max2 = -1;
		maxk1 = 0;
		maxk2 = 0;
		vecesT1mejor = 0;
		vecesT2mejor = 0;
		promT1mejor = 0;
		promT2mejor = 0;

		for(int rep = 0; rep < 10000; rep++)
		{
			AdyMatrix A = createBadGraphForGreedy(i);
			n = A.size();
			Solucion sol;
			maxF1 = 0;
			maxF2 = 0;
			for(int k = 1; k <= n/3; k++)
			{
				sol = hTabu1(A, n, k, maxRep);
			//cout << "t1 ok ";
				if(maxF1 < sol.F)
				{
					maxF1 = sol.F;
					maxk1 = max(maxk1, k);
				}

				max1 = max(max1, maxRep);
				sol = hTabu2(A, n, k, maxRep);
			//cout << "t2 ok" << endl;
				if(maxF2 < sol.F)
				{
					maxF2 = sol.F;
					maxk2 = max(maxk2, k);
				}

				max2 = max(max2, maxRep);

			}
			if(maxF1 > maxF2)
			{
				vecesT1mejor++;
				promT1mejor += (maxF1 - maxF2);
			}
			if(maxF1 < maxF2)
			{
				vecesT2mejor++;
				promT2mejor += (maxF2 - maxF1);
			}
		}
		promT1mejor = (vecesT1mejor > 0) ? ceil(promT1mejor/vecesT1mejor) : 0;
		promT2mejor = (vecesT2mejor > 0) ? ceil(promT2mejor/vecesT2mejor) : 0;

		cout << n << " " << vecesT1mejor << " " << promT1mejor << " " << vecesT2mejor << " " << promT2mejor << endl;
	}
}

void testTabus2()
{
	int maxRep, max1, max2, max3, max4, maxF1, maxF2, maxF3, maxF4, maxk1, maxk2, maxk3, maxk4;
	int m, vecesT1mejor, vecesT2mejor, vecesT3mejor, vecesT4mejor;

	double promT1mejor, promT2mejor, promT3mejor, promT4mejor;

	cout << "# N veces_Tx_mejor " << endl;

	int n;
	for(int i = 5; i <= 10; i++)
	//for(int n = 15; n <= 35; n+=10)
	{
		max1 = -1;
		max2 = -1;
		max3 = -1;
		max4 = -1;
		maxk1 = 0;
		maxk2 = 0;
		maxk3 = 0;
		maxk4 = 0;
		vecesT1mejor = 0;
		vecesT2mejor = 0;
		vecesT3mejor = 0;
		vecesT4mejor = 0;

		int BvecesT1mejor = 0;
		int BvecesT2mejor = 0;
		int BvecesT3mejor = 0;
		int BvecesT4mejor = 0;
		promT1mejor = 0;
		promT2mejor = 0;
		promT3mejor = 0;
		promT4mejor = 0;

		for(int rep = 0; rep < 10000; rep++)
		{
			//AdyMatrix A = crearGrafoAleatorio(n, m);
			Solucion sol;
			AdyMatrix A = createBadGraphForGreedy(i);
			n = A.size();
			maxF1 = 0;
			maxF2 = 0;
			maxF3 = 0;
			maxF4 = 0;
			for(int k = 1; k <= n/3; k++)
			{
				sol = hTabu3(A, n, k, maxRep, 0);
				if(maxF1 < sol.F)
				{
					maxF1 = sol.F;
					maxk1 = max(maxk1, k);
				}

				max1 = max(max1, maxRep);

				sol = hTabu3(A, n, k, maxRep, 1);
				if(maxF2 < sol.F)
				{
					maxF2 = sol.F;
					maxk2 = max(maxk2, k);
				}

				max2 = max(max2, maxRep);

				sol = hTabu3(A, n, k, maxRep, 2);
				if(maxF3 < sol.F)
				{
					maxF3 = sol.F;
					maxk3 = max(maxk3, k);
				}
				max3 = max(max3, maxRep);

				sol = hTabu3(A, n, k, maxRep, 3);
				if(maxF4 < sol.F)
				{
					maxF4 = sol.F;
					maxk4 = max(maxk4, k);
				}
				max4 = max(max4, maxRep);

			}
			if(maxF1 > maxF2 && maxF1 > maxF3 && maxF1 > maxF4)
			{
				vecesT1mejor++;
				promT1mejor += (maxF1 - max(maxF2, max(maxF3, maxF4)));
			}
			if(maxF2 > maxF1 && maxF2 > maxF3 && maxF2 > maxF4)
			{
				vecesT2mejor++;
				promT2mejor += (maxF2 - max(maxF1, max(maxF3, maxF4)));
			}
			if(maxF3 > maxF2 && maxF3 > maxF1 && maxF3 > maxF4)
			{
				vecesT3mejor++;
				promT3mejor += (maxF3 - max(maxF2, max(maxF1, maxF4)));
			}
			if(maxF4 > maxF2 && maxF4 > maxF3 && maxF4 > maxF1)
			{
				vecesT4mejor++;
				promT4mejor += (maxF4 - max(maxF2, max(maxF3, maxF1)));
			}

			if(maxF1 >= maxF2 && maxF1 >= maxF3 && maxF1 >= maxF4)
			{
				BvecesT1mejor++;
			}
			if(maxF2 >= maxF1 && maxF2 >= maxF3 && maxF2 >= maxF4)
			{
				BvecesT2mejor++;
			}
			if(maxF3 >= maxF2 && maxF3 >= maxF1 && maxF3 >= maxF4)
			{
				BvecesT3mejor++;
			}
			if(maxF4 >= maxF2 && maxF4 >= maxF3 && maxF4 >= maxF1)
			{
				BvecesT4mejor++;
			}
		}
		/*
		promT1mejor = (vecesT1mejor > 0) ? ceil(promT1mejor/vecesT1mejor) : 0;
		promT2mejor = (vecesT2mejor > 0) ? ceil(promT2mejor/vecesT2mejor) : 0;
		promT3mejor = (vecesT3mejor > 0) ? ceil(promT3mejor/vecesT3mejor) : 0;
		promT4mejor = (vecesT4mejor > 0) ? ceil(promT4mejor/vecesT4mejor) : 0;
		*/

		cout << n << " " << vecesT1mejor << " " << vecesT2mejor << " " << vecesT3mejor << " " << vecesT4mejor << endl;
		cout << n << " " << BvecesT1mejor << " " << BvecesT2mejor << " " << BvecesT3mejor << " " << BvecesT4mejor << endl;
	}
}

void testTabus3()
{
	int m, maxRep, maxR, mejorK, minK, maxK, maxgen, maxF, cantK;


	cout << "# N maxAparicionK minK maxK max_iter_hasta_mejora" << endl;

	int n;
	for(int i = 5; i <= 10; i++)
	//for(int n = 15; n <= 40; n+=5)
	{
		maxR = 0;
		maxK = 0;
		minK = 10000;
		cantK = 0;
		maxgen = 1;
		vector<int> maxAp(30, 0);

		for(int rep = 0; rep < 10000; rep++)
		{
			//AdyMatrix A = crearGrafoAleatorio(n, m);
			AdyMatrix A = createBadGraphForGreedy(i);
			n = A.size();

			Solucion sol;
			maxF = 0;
			mejorK = 0;
			for(int k = 1; k <= n/2; k++)
			{
				sol = hTabu(A, n, k, maxRep);
			//cout << "t1 ok ";
				if(maxF < sol.F)
				{
					maxF = sol.F;
					if(mejorK < k)
					{
						maxAp[mejorK]--;
						maxAp[k]++;
						mejorK = k;
					}
				}

				maxR = max(maxR, maxRep);
			}

			maxK = max(maxK, mejorK);
			if(mejorK > 1)
			{
				minK = min(minK, mejorK);
				cantK++;
			}
		}

		if(minK > 1000)
				minK = 0;

		int aux = 0;
		for(int i = minK; i < maxK; i++)
		{
			if(maxAp[i] >= aux)
			{
				aux = maxAp[i];
				maxgen = i;
			}
		}

		cout << n << " " << maxgen << " " << minK << " " << maxK << " " << maxR << endl;
	}
}

void testTabus4()
{
	int m, maxRep, maxR, k2, k3, kmax, k2b, k3b, kmaxb;


	cout << "# N k2_mejor k3_mejor kmax_mejor max_iter_hasta_mejora" << endl;

	int n;
	for(int i = 5; i <= 10; i++)
	//for(int n = 15; n <= 40; n+=5)
	{
		maxR = 0;
		k2 = 0;
		k3 = 0;
		kmax = 0;

		for(int rep = 0; rep < 10000; rep++)
		{
			//AdyMatrix A = crearGrafoAleatorio(n, m);
			AdyMatrix A = createBadGraphForGreedy(i);
			n = A.size();
			Solucion sol;

			sol = hTabu(A, n, 2, maxRep);
			k2b = sol.F;
			maxR = max(maxR, maxRep);

			sol = hTabu(A, n, 3, maxRep);
			k3b = sol.F;
			maxR = max(maxR, maxRep);

			sol = hTabu(A, n, n/3, maxRep);
			kmaxb = sol.F;
			maxR = max(maxR, maxRep);

			if(k2b >= k3b && k2b >= kmaxb)
				k2++;
			if(k3b >= k2b && k3b >= kmaxb)
				k3++;
			if(kmaxb >= k2b && kmaxb >= k3b)
				kmax++;
		}

		cout << n << " " << k2 << " " << k3 << " " << kmax << " " << maxR << endl;
	}
}

void ultimoPunto()
{

	int rep = 500;
	cout << "#ultimoPunto ej4" << endl;
	cout << "#N promGL promLT maxGL maxLT ptG+L ptT" << endl;

	for(int i = 10; i <= 200; i+=10)
	{
		int maxGL = 0, maxLT = 0, mejoragl = 0, mejoralt = 0;
		double promGL = 0, promLT = 0;

		double ptG = 0, ptL= 0, ptT = 0;
		for(int r = 0; r < rep; r++)
		{
			int m;
			AdyMatrix A = crearGrafoAleatorio(i, m);

			Solucion res;

			ptG -= (double)clock();
			res = hGolosa(A, i);
			ptG += (double)clock();
			int fg = res.F;

			ptL -= (double)clock();
			res = hLocal(A,res,i);
			ptL += (double)clock();
			int fl = res.F;

			int q = 0;
			ptT -= (double)clock();
			res = hTabu(A,i, i/3, q);
			ptT += (double)clock();
			int ft = res.F;

			if(fl > fg)
			{
				promGL += (fl - fg);
				maxGL = max(maxGL, fl - fg);
				mejoragl++;
			}
			if(ft > fl)
			{
				promLT += (ft - fl);
				maxLT = max(maxLT, ft - fl);
				mejoralt++;
			}
		}

		promGL = (mejoragl > 0) ? round(promGL/mejoragl) : 0;
		promLT = (mejoralt > 0) ? round(promLT/mejoralt) : 0;

		ptG /= rep;
		ptL /= rep;
		ptT /= rep;

		ptG = round(ptG / 1000);
		ptL = round(ptL / 1000);
		ptT = round(ptT / 1000);

		cout << i << " " << promGL << " " << promLT << " " << maxGL << " " << maxLT << " " << ptG+ptL << " " << ptT << endl;
	}
}

int main()
{

	//tests para correr casos aleatorios usando el exacto como comparacion
	// analisisAleatorio();
	//test para correr casos aleatorios identico al anterior pero sin el exacto
	// mejoraAleatorio();
	//test en donde corremos el tabú con el grafo que es el peor caso
	mejoraMalo();
	//test de tabu con el caso de un grafo K regular 
	// analisisKRegular();

	/*
	testTabus();
	testTabus2();
	testTabus3();
	testTabus4();
	*/
	return 0;
}
