#include "includes.h"

int main(){

	int n = 0;
	cin >> n;
	while (n != -1) {
		vector <vector < int > > costo;

		getInputEj3(costo,n);//guarda en las matriz de adyacencia todos los valores

		AdyacencyList lista = AdyacencyList(costo.size(), costo.size()*(costo.size()-1)/2);

		lista.matrixToList(costo);//me guardo una lista de adyacencia

		lista.getAGMWeigth();//calculo el AGM

		cout<<lista.peso<<" "<<lista.calles<<" ";

		imprimir_vector(lista.origen,lista.destino,lista.origen.size()); // vamos a mostrar las ciudades conectadas
			
		cin >> n;
	}
	return 0;
}
