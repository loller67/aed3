#include "Solucion.h"

void Solucion::print()
{
	cout << F << " " << k << endl;
	for(int i = 0; i < k-1; i++)
	{
		cout << v[i] << " ";
	}
	cout << v[k-1];
}

ostream& operator<<(ostream& os, const Solucion& s)
{
    os << s.F << " " << s.k << endl;
    for(int i = 0; i < s.k-1; i++)
	{
		os << s.v[i] << " ";
	}
	os << s.v[s.k-1];

    return os;
}
