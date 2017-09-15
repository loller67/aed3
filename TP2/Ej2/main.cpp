#include "bfmod.h"


using namespace std;

int main()
{
	//n ciudades, m rutas
	int n, m, cmin = INT_MAX, cmax = -1; 	//pesos minimos y maximos
	cin >> n;
	cin >> m;

	while(n != -1)
	{
		cmin = INT_MAX, cmax = -1; 	//pesos minimos y maximos
		vector<Arista > aristas(m, Arista(-1,-1,-1));

		for(int i = 0; i < m; i++)
		{
			cin >> aristas[i].origen;
			cin >> aristas[i].destino;
			cin >> aristas[i].peso;

			//el valor C a reducir esta en [cmin, cmax), a menos que cmax = cmin
			if(aristas[i].peso > cmax)
				cmax = aristas[i].peso;
			if(aristas[i].peso < cmin)
				cmin = aristas[i].peso;
		}
		if(cmax-cmin < 2)
		{
			cout << cmin << endl;
			return 0;
		}

		int res = ejercicio2(n, m, cmin, cmax, aristas);

		cout << res << endl;

		cin >> n;
		cin >> m;
	}

	return 0;
}
