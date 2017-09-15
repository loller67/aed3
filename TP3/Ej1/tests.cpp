#include "Exacto.h"
#include <chrono>
#include "../aux/Generadores/generador.h"
#define ya chrono::high_resolution_clock::now



void test_Kn(int Tam,int repeticiones,int salto) {

	for (int i = 1; i < Tam; i++) {
		std::cout << "tamaño: " <<i*salto <<'\n';
		AdyMatrix matrix(i*salto);
		matrix.grafoCompleto();
		for (int j = 0; j < repeticiones; j++) {
			auto start = ya();
			Solucion sol = Ej1(matrix,i,i);
			auto end = ya();
			cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
		}

	}
}


void test_path(int Tam, int repeticiones,int salto) {
	for (int i = 1; i < Tam; i++) {
		std::cout << "tamaño: " <<i*salto <<'\n';
		int tamanio = i*salto;
		AdyMatrix B = createPathGraph(tamanio);
		for (int j = 0; j < repeticiones; j++) {
			auto start = ya();
			Solucion sol = Ej1(B,i,i);
			auto end = ya();
			cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
		}

	}
}




void test_bipartite(int Tam, int repeticiones,int salto) {
	for (int i = 1; i < Tam; i++) {
		std::cout << "tamaño: " <<i*salto <<'\n';
		int tamanio = i*salto;
		AdyMatrix B = createBipartiteGraph(tamanio);
		for (int j = 0; j < repeticiones; j++) {
			auto start = ya();
			Solucion sol = Ej1(B,i,i);
			auto end = ya();
			cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
		}

	}
}


void test_star(int Tam, int repeticiones,int salto) {
	for (int i = 1; i < Tam; i++) {
		std::cout << "tamaño: " <<i*salto <<'\n';
		int tamanio = i*salto;
		AdyMatrix B = createStarGraph(tamanio);
		for (int j = 0; j < repeticiones; j++) {
			auto start = ya();
			Solucion sol = Ej1(B,i,i);
			auto end = ya();
			cout << chrono::duration_cast<std::chrono::microseconds>(end-start).count()<< "\n";
		}

	}
}



int main() {
	int tam = 27;
	int repeticiones = 10;
	int salto = 5;
	std::cout << "complete graph" << '\n';
	test_Kn(tam,repeticiones,salto);
	std::cout << "path graph: " << '\n';
	test_path(tam,repeticiones,salto);
	std::cout << "bipartite graph: " << '\n';
	test_bipartite(tam,repeticiones,salto);
	std::cout << "star graph: " << '\n';
	test_star(tam,repeticiones,salto);
return 0;
}
