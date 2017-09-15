#include "tabu.h"

int main()
{
	/**
		Cada instancia representa un grafo G y comienza con una lı́nea con dos valores
		enteros n y m separados por espacios. Estos valores indican la cantidad de vértices y aristas de G,
		respectivamente. A continuación, le siguen m lı́neas, cada una determinando una arista del grafo.
	*/
	int n, m;
	cin >> n;
	cin >> m;

	AdyMatrix M(n);

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;

		M.addEdge(min(a,b),max(a,b));

	}
	int q = 0;
	Solucion res = hTabu(M, n, n/3, q);

	cout << res << endl;

	return 0;
}