
#include "generador.h"
#include "../AdyMatrix/AdyMatrix.h"
#include <string>
#include <iostream>

using namespace std;

void print_graph(int from, int to, AdyMatrix (*graphGenerator)(int, int), string graphType){

	for(int i = from; i <= to; i++){
		AdyMatrix graph = graphGenerator(4, i);
		cout << "Grafo " << graphType << " de " << i << " nodos" << endl;
		graph.print();
	}
}

int main(){
	int from = 4;
	int to = 10;

	// print_graph(from, to, createCompleteGraph, "completo");
	// print_graph(from, to, createCicleGraph, "ciclo");
	// print_graph(from, to, createPathGraph, "camino");
	// print_graph(from, to, createStarGraph, "estrella");
	// print_graph(from, to, createBinaryTreeBalanced, "arbol binario");
	// print_graph(from, to, createBipartiteGraph, "bipartito completo");
	print_graph(from, to, createKRegularRandomGraph, "malo para goloso");
	/*
	int n ;
	cin >> n ;
	createMixGraph(n);
	*/

}
