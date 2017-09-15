#include "bfmod.h"

bool BellmanFordModificado(int n, int m, vector<Arista> &aristas, int resta)
{
	vector<int> distancia(n,0);	//como simulo que hay un vector que se une a todos con peso 0, todos los nodos empiezan con distancia 0.
	for(int i = 0; i < n; i++)	//puede haber n-1 cambios sin ciclos negativos.
	{
		for(int j = 0; j < m; j++)
		{
			//i++;
			int p = aristas[j].origen-1;
			int q = aristas[j].destino-1;
			int w = aristas[j].peso;

			if(distancia[p] + w - resta < distancia[q])
				distancia[q] = distancia[p] + w - resta;
		}
	}

	for(int j = 0; j < m; j++)
	{
		//i++;
		int p = aristas[j].origen-1;
		int q = aristas[j].destino-1;
		int w = aristas[j].peso;

		if(distancia[p] + w - resta < distancia[q])
		{
			return false;	//hay un ciclo negativo	
		}
	}
	return true;
}

int ejercicio2(int n, int m, int cmin, int cmax, vector<Arista> &aristas)
{
	int vini = cmin, vfin = cmax, v = floor((vfin + vini)/2);
	do
	{
		bool sinCiclosNeg = BellmanFordModificado(n,m,aristas,v);
		if(sinCiclosNeg)
		{
			vini = v;
			v = floor((vfin + vini)/2);
		}
		else
		{
			vfin = v;
			v = floor((vfin + vini)/2);
		}
	}while(vfin-vini >= 2);

	return vini;
}