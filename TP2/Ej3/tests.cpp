#include "includes.h"
#include <chrono>
#define ya chrono::high_resolution_clock::now



void getInputIguales(vector <vector < int > > &costo,int n){
	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		costo.push_back(row); // Add the row to the main vector
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			costo[x][y]=0;
		}
	}
// i es la ciudad de partida
//j es la ciudad de llegada
	int peso = 10;
	for (int i = 1; i < n+1; i++) {
		for (int j = i+1; j < n+1; j++) {
			int estaConstruido = 0;
			if(estaConstruido==1){
				costo[i-1][j-1]=-peso;
				costo[j-1][i-1]=-peso;
			}else{
				costo[i-1][j-1]=peso;
				costo[j-1][i-1]=peso;
			}
		}
	}
}


void getInputCreciente(vector <vector < int > > &costo,int n){
	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		costo.push_back(row); // Add the row to the main vector
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			costo[x][y]=0;
		}
	}
// i es la ciudad de partida
//j es la ciudad de llegada
	int peso = 0;
	int k = 1;
	for (int i = 1; i < n+1; i++) {
		for (int j = i+1; j < n+1; j++) {
	//		int estaConstruido = rand() % 2;
			int estaConstruido = 0;
			peso = k;
			k++;
			if(estaConstruido==1){
				costo[i-1][j-1]=-peso;
				costo[j-1][i-1]=-peso;
			}else{
				costo[i-1][j-1]=peso;
				costo[j-1][i-1]=peso;
			}
		}
	}
}



void getInputDecreciente(vector <vector < int > > &costo,int n,int max){
	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		costo.push_back(row); // Add the row to the main vector
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			costo[x][y]=0;
		}
	}
// i es la ciudad de partida
//j es la ciudad de llegada
	int peso = 0;
	int k = max;
	for (int i = 1; i < n+1; i++) {
		for (int j = i+1; j < n+1; j++) {
	//		int estaConstruido = rand() % 2;
			int estaConstruido = 0;
			peso = k;
			k--;
			if(estaConstruido==1){
				costo[i-1][j-1]=-peso;
				costo[j-1][i-1]=-peso;
			}else{
				costo[i-1][j-1]=peso;
				costo[j-1][i-1]=peso;
			}
		}
	}
}




void getInputAlternado(vector <vector < int > > &costo,int n,int max){
	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		costo.push_back(row); // Add the row to the main vector
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			costo[x][y]=0;
		}
	}
// i es la ciudad de partida
//j es la ciudad de llegada
	int peso = 0;
	int k = max;
	int l = 0;
	for (int i = 1; i < n+1; i++) {
		for (int j = i+1; j < n+1; j++) {
	//		int estaConstruido = rand() % 2;
			int estaConstruido = 0;

			if (l % 2 == 0) {
				peso = k;
			}
			else{
				peso = l;
			}
			k--;
			l++;
			if(estaConstruido==1){
				costo[i-1][j-1]=-peso;
				costo[j-1][i-1]=-peso;
			}else{
				costo[i-1][j-1]=peso;
				costo[j-1][i-1]=peso;
			}
		}
	}
}










void getInputRandom(vector <vector < int > > &costo,list<int> &random){

int n = random.size();
list<int>::iterator it=random.begin();

	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		costo.push_back(row); // Add the row to the main vector
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			costo[x][y]=0;
		}
	}
// i es la ciudad de partida
//j es la ciudad de llegada
	for (int i = 1; i < n+1; i++) {
		for (int j = i+1; j < n+1; j++) {
			int estaConstruido = 0;
			int peso = *it;
			it++;
			if(estaConstruido==1){
				costo[i-1][j-1]=-peso;
				costo[j-1][i-1]=-peso;
			}else{
				costo[i-1][j-1]=peso;
				costo[j-1][i-1]=peso;
			}
		}
	}
}


void testIguales(int i,int repeticiones) {

	for (int j = 0; j < repeticiones; j++) {

		vector <vector < int > > costoIguales;
		getInputIguales(costoIguales,i);
		auto start = ya();
		AdyacencyList listaIguales = AdyacencyList(costoIguales.size(), costoIguales.size()*(costoIguales.size()-1)/2);
		listaIguales.matrixToList(costoIguales);//me guardo una listaIguales de adyacencia
		listaIguales.getAGMWeigth();//calculo el AGM
		// cout<<listaIguales.peso<<" "<<listaIguales.calles<<" ";
		// imprimir_vector(listaIguales.arbol,listaIguales.arbol.size()); // vamos a mostrar las ciudades conectadas
		auto end = ya();
		cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
	}
}

void testCreciente(int i,int repeticiones) {
	for (int j = 0; j < repeticiones; j++) {
		vector <vector < int > > costoCreciente;
		getInputCreciente(costoCreciente,i);
		auto start = ya();
		AdyacencyList listaCreciente = AdyacencyList(costoCreciente.size(), costoCreciente.size()*(costoCreciente.size()-1)/2);
		listaCreciente.matrixToList(costoCreciente);//me guardo una listaCreciente de adyacencia
		listaCreciente.getAGMWeigth();//calculo el AGM
		// cout<<listaCreciente.peso<<" "<<listaCreciente.calles<<" ";
		// imprimir_vector(listaCreciente.arbol,listaCreciente.arbol.size()); // vamos a mostrar las ciudades conectadas
		auto end = ya();
		cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";

	}
}

void testDecreciente(int i,int repeticiones,int max) {
	for (int j = 0; j < repeticiones; j++) {
		vector <vector < int > > costoDecreciente;
		getInputDecreciente(costoDecreciente,i,max);
		auto start = ya();
		AdyacencyList listaDecreciente = AdyacencyList(costoDecreciente.size(), costoDecreciente.size()*(costoDecreciente.size()-1)/2);
		listaDecreciente.matrixToList(costoDecreciente);//me guardo una listaDecreciente de adyacencia
		listaDecreciente.getAGMWeigth();//calculo el AGM
		// cout<<listaDecreciente.peso<<" "<<listaDecreciente.calles<<" ";
		// imprimir_vector(listaDecreciente.arbol,listaDecreciente.arbol.size()); // vamos a mostrar las ciudades conectadas
		auto end = ya();
		cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
	}
}



void testAlternado(int i,int repeticiones,int max) {
	for (int j = 0; j < repeticiones; j++) {
		vector <vector < int > > costoAlternado;
		getInputAlternado(costoAlternado,i,max);
		auto start = ya();
		AdyacencyList listaAlternada = AdyacencyList(costoAlternado.size(), costoAlternado.size()*(costoAlternado.size()-1)/2);
		listaAlternada.matrixToList(costoAlternado);//me guardo una listaAlternada de adyacencia
		listaAlternada.getAGMWeigth();//calculo el AGM
		// cout<<listaAlternada.peso<<" "<<listaAlternada.calles<<" ";
		// imprimir_vector(listaAlternada.arbol,listaAlternada.arbol.size()); // vamos a mostrar las ciudades conectadas
		auto end = ya();
		cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
	}
}









void testRandom(int i,int repeticiones, list<int> &random) {

	for (int j = 0; j < repeticiones; j++) {
		vector <vector < int > > costoRandom;
		getInputRandom(costoRandom,random);
		auto start = ya();
		AdyacencyList listaRandom = AdyacencyList(costoRandom.size(), costoRandom.size()*(costoRandom.size()-1)/2);
		listaRandom.matrixToList(costoRandom);//me guardo una listaRandom de adyacencia
		listaRandom.getAGMWeigth();//calculo el AGM
		// cout<<listaRandom.peso<<" "<<listaRandom.calles<<" ";
		// imprimir_vector(listaRandom.arbol,listaRandom.arbol.size()); // vamos a mostrar las ciudades conectadas
		auto end = ya();
		cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
	}
}

int main(){


int repeticiones = 10;
int tam = 500;
list<int> random;
random.push_back(rand() % 500);
random.push_back(rand() % 500);


	for (int i = 2; i < tam; i++) {
		random.push_back(rand() % 500);
		std::cout << i <<'\n';

		std::cout << "Inicio test Iguales" << '\n';
		testIguales(i,repeticiones);

		std::cout << "Inicio test Creciente" << '\n';
		testCreciente(i,repeticiones);

		std::cout << "Inicio test Decreciente" << '\n';
		testDecreciente(i,repeticiones,tam);

		std::cout << "Inicio test Alternado" << '\n';
		testAlternado(i,repeticiones,tam);

		std::cout << "Inicio test Random" << '\n';
		testRandom(i,repeticiones,random);
	}

return 0;
}
