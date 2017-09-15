#include "../AdyMatrix/AdyMatrix.h"
#include "generador.h"
#include <time.h>

using namespace std;


AdyMatrix createCompleteGraph(int nodes_quantity){

	AdyMatrix graph = AdyMatrix(nodes_quantity);
	graph.grafoCompleto();
	return graph;
}

AdyMatrix createBipartiteGraph(int nodes_quantity){
	AdyMatrix graph = AdyMatrix(nodes_quantity);

	int first_half = nodes_quantity/2;

	for(int i = 0; i < first_half; i++){
		for (int j = first_half; j < nodes_quantity; j++){
			graph.addEdge(i, j);
		}
	}
	return graph;
}

AdyMatrix createStarGraph(int nodes_quantity){
	AdyMatrix graph = AdyMatrix(nodes_quantity);

	for(int i = 1; i < nodes_quantity; i++){
		graph.addEdge(i, 0);
	}

	cout << "grafo estrella si creado" << endl;
	return graph;
}


AdyMatrix createPathGraph(int nodes_quantity){

	AdyMatrix graph = AdyMatrix(nodes_quantity);

	for(int i = 1; i < nodes_quantity; i++){
		graph.addEdge(i, i-1);
	}
	return graph;
}

AdyMatrix createCicleGraph(int nodes_quantity){
	AdyMatrix graph = createPathGraph(nodes_quantity);
	if(nodes_quantity>1){
		graph.addEdge(0, nodes_quantity-1);
	}
	return graph;
}

AdyMatrix createBinaryTreeBalanced(int nodes_quantity){

	AdyMatrix graph = AdyMatrix(nodes_quantity);

	for (int i = 1; i < nodes_quantity; ++i){
		int father = (i-1)/2;
		graph.addEdge(i, father);
	}

	return graph;
}




AdyMatrix createMixGraph(int nodes_quantity){

	AdyMatrix graph = AdyMatrix(nodes_quantity);


	list<int> l;
	int tamanio = nodes_quantity-1;
	int i = 2;
	while (tamanio > i) {
		l.push_back(i);
		tamanio = tamanio -i;
		i++;
	}
	int suma = nodes_quantity-1-tamanio;

	if (tamanio > 0) {
		l.push_back(nodes_quantity-1-suma);
	}
	int posicion = 0;
	int fin = 0;
	for (std::list<int>::iterator it=l.begin(); it != l.end(); ++it){
		fin = fin +*it;
		for (int i = posicion; i < fin; i++) {
			for (int j = posicion; j < fin; j++) {
				if (i!=j) {
					graph.addEdge(i,j);
				}
			}
		}
		posicion = fin;
	}
	int conector = -1;
	for (std::list<int>::iterator it=l.begin(); it != l.end(); ++it){
		conector = conector + *it;
		graph.addEdge(nodes_quantity-1,conector);
		graph.addEdge(nodes_quantity-1,conector);
	}
return graph;
}



AdyMatrix createMagicGraph(int nodes_quantity, int cliques)
{
	/**
		1)Primero crea aristas random desde cada nodo.
		2)Luego crea cliques.
	*/

	clock_t extra = clock();
	srand(time(NULL)*(double)extra);

	int n = nodes_quantity;
	
	AdyMatrix graph = AdyMatrix(nodes_quantity);

	//1)
	for(int x = 0; x < n; x++)
	{
		int y;
		do{
			y = rand() % n;
		}while(y == x);

		graph.addEdge(x,y);
	}

	//mas aristas
	for(int x = n; x <= 2*n; x++)
	{
		int x2,y;
		do{
			x2 = rand() % n;
			y = rand() % n;
		}while(y == x2);

		graph.addEdge(x2,y);
	}

	//2)
	while(cliques > 0){
		cliques--;

		vector<int> nuevaClique;

		for(int k = 0; k < n; k++)
		{
			if(rand()%3)
				nuevaClique.push_back(k);
		}
		//cout << nuevaClique.size() << endl;
		//creo aristas entre cada elemento de nuevaClique
		for(int i=0;i<(int)nuevaClique.size()-1;i++){
			for(int j=i+1;j<(int)nuevaClique.size();j++){
				graph.addEdge(nuevaClique[i], nuevaClique[j]);
			}
		}
	}
	return graph;
}



AdyMatrix createBadGraphForGreedy(int kn_size){

	int nodos_totales = kn_size + kn_size*(kn_size+1);

	AdyMatrix graph = AdyMatrix(nodos_totales);

	//Creo el subgrafo completo
	for(int i = 0; i < kn_size; ++i){
		for(int j = 0 ; j < kn_size; j++){
			if(i!=j){
				graph.addEdge(i, j);
			}
		}
	}

	//Creo las ramitas, una por cada nodo del kn
	for(int i = 0; i<kn_size; i++){

		int nodo_principal = kn_size + i*(kn_size+1);
		int nodo_principal_siguiente = kn_size + (i+1)*(kn_size+1);

		for(int j = nodo_principal +1; j <nodo_principal_siguiente; j++){
			graph.addEdge(nodo_principal, j);
		}

		//Conecto la punta con la esquina del kn
		graph.addEdge(i, nodo_principal);

	}

	return graph;
}

/*
	Tengo 4 grupos de nodos.
	Un grafo kn.
	Un conjunto de n/2 nodos que fomran un subgrafo completo.
	Un conjunto de n/2 (+1 si n es impar) nodos que forman un subgrafo completo.
	Cada nodo de estos conjuntos se conecta a un unico nodo sin repetir del grafo kn.
	Un cuarto conjunto de n/2 +1 (+1 si n es impar) que cada nodo se conecta con todos los nodos delsegundo y tercer grupo.
*/

AdyMatrix createBadGraphForGreedyVersion2(int kn_size){


	
	int indice_primer_nodo_primer_grupo = kn_size;
	int indice_primer_nodo_segundo_grupo = indice_primer_nodo_primer_grupo + kn_size;
	int nodos_totales = indice_primer_nodo_segundo_grupo + kn_size + 1;

	AdyMatrix graph = AdyMatrix(nodos_totales);

	//Creo el subgrafo completo
	for(int i = 0; i < kn_size; ++i){
		for(int j = 0 ; j < kn_size; j++){
			if(i!=j){
				graph.addEdge(i, j);
			}
		}
	}

	//Conecto los nodos de kn al primer grupo
	for(int i = 0; i < kn_size; ++i){
		int nodo_al_que_conecta = i +kn_size;
		graph.addEdge(i, nodo_al_que_conecta);
	}

	//Creo el subgrafo bipartito entre el segundo grupo y el primero
	for(int i = indice_primer_nodo_primer_grupo; i < indice_primer_nodo_segundo_grupo; ++i){
		for(int j = indice_primer_nodo_segundo_grupo ; j < nodos_totales; j++){
			if(i!=j){
				graph.addEdge(i, j);
			}
		}
	}


	return graph;
}


AdyMatrix createKRegularRandomGraph(int k, int n){
	
	
	if( k >= n){
		cout << "K es muy grande para el grafo" << endl;
		return AdyMatrix(n);
	}
	if( (k % 2 == 1) && (n %2 ==1)){
		cout << "k y n impares no se pueden hacer k regular" << endl;
		return AdyMatrix(n);
	}
	
	AdyMatrix graph = AdyMatrix(n);

	int half = k/2;
	//cout << half << endl;

	//Para cada nodo
	for(int i = 0; i < n; i++){
		
		//Para los half vecinos de la derecha
		for(int j = 1; j<= half; j++){
			int nodo_vecino = (i + j) % n;
			graph.addEdge(i,nodo_vecino);
		}
		

		//Si k es impar y me falta un nodo, lo conecto con el de enfrente
		if(k%2 == 1){
			int nodo_de_enfrente = (i+ n/2 )%n;
			graph.addEdge(i,nodo_de_enfrente);
		}
	}

	//Randomizo
	graph.shuffle();
	
	
	return graph;
}

/*
AdyMatrix createKRRGraph(int k, int n){//LLAMENLO CON K Y N PAR SI NO NO LES DEVUELVE NADA
	
	
	if( k >= n){
		cout << "K es muy grande para el grafo" << endl;
		return AdyMatrix(n);
	}
	if( (k % 2 == 1) || (n %2 ==1)){
		cout << "k y n impares no se pueden hacer k regular" << endl;
		return AdyMatrix(n);
	}
	
	AdyMatrix graph = AdyMatrix(n);

	graph.grafoCompleto();//creo el grafo completo

	vector<int> chosen;

	for(int i = 0; i < n; i++){
		
		chosen.push_back(i);


	}

	int contador =0;

	for(int j=0;j<n;j++){

		if(graph.degree(j)>n-k-1 || j==0){
	
			contador=0;
			int total=graph.degree(j)-k;//esta es la cantidad de ejes que me gustaria eliminar del grafo para que quede de grado k
			random_shuffle( chosen.begin(), chosen.end() );//randomizo los elementos de chosen para el orden de selección

			for(int i=0; contador<total ; i++){
				if(((graph.degree(chosen[i]) > k ) && graph.degree(j)>k) || (chosen[i]!=j)){//si el grado del elemento es mayor a k o el elemento es distinto a si mismo
					contador++;
					graph.removeEdge(chosen[i],j);// elimino el eje, es decir le resto 1 grado hasta llegar a k
				}

			}

		}
	}	
	return graph;
}
*/