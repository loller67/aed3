#include "AdyMatrix.h"
#include <cstdlib>

//using namespace std;

AdyMatrix::AdyMatrix(){
	edgesQ = 0;
	nodesQ = 0;
	matrix = vector<vector<int> >(1, vector<int>(1));
}

AdyMatrix::AdyMatrix(int n){
	nodesQ = n;
	edgesQ = 0;
	matrix = vector<vector<int> >(n, vector<int>(n,0));
}

AdyMatrix::AdyMatrix(const AdyMatrix& aM) 
{
	matrix = aM.matrix;
	nodesQ = aM.nodesQ;
	edgesQ = aM.edgesQ;
}

AdyMatrix::AdyMatrix(int n, int k){
	nodesQ = n;
	matrix = vector<vector<int> >(n, vector<int>(n,k));	
}

AdyMatrix::~AdyMatrix() {
}

void AdyMatrix:: set(int i,int j,int val){

		if(i<nodesQ && j<nodesQ)
			matrix[i][j]=val;
}
		
		
int AdyMatrix:: get (int i,int j){
		
	if(i<nodesQ && j<nodesQ)
		return matrix[i][j];
	else
	{
		cout << "Error al querer leer las posiciones i=" << i << ", j=" << j << " en matriz de " << nodesQ << "x" << nodesQ << " = " << matrix.size() << endl;
		return -1;
	}
}
		
int& AdyMatrix::operator() (int i, int j)
{
	if(i<nodesQ && j<nodesQ)
		return matrix[i][j];
	else
	{
		//cout << "Error al querer leer las posiciones i=" << i << ", j=" << j << endl;
		return matrix[0][0];
	}
}

void AdyMatrix::operator=(AdyMatrix aM)
{
	matrix = aM.matrix;
	nodesQ = aM.nodesQ;
	edgesQ = aM.edgesQ;
}


void AdyMatrix::addEdge(int n1, int n2){

		//assert(n1==n2);
		//assert(matrix[n1][n2]>=1 ||matrix[n2][n1]>=1);
	if(n1 != n2)
	{
		matrix[n1][n2]=1;
		matrix[n2][n1]=1;
	}
	matrix[n1][n1]=0;
	matrix[n2][n2]=0;

	edgesQ++;
}

void AdyMatrix::addEdge(int n1, int n2, int w){

		//assert(n1==n2);
		//assert(matrix[n1][n2] ||matrix[n2][n1]);
	if(n1 != n2)
	{
		matrix[n1][n2]=w;
		matrix[n2][n1]=w;
	}
	matrix[n1][n1]=0;
	matrix[n2][n2]=0;

	edgesQ++;
}

void AdyMatrix::print(){
	for(int i = 0; i < nodesQ; i++){
		cout << '[';
		for(int j=0;j<nodesQ;j++){
			cout << matrix[i][j];
			if(j != nodesQ-1) 
				cout << ", ";
		}
		cout << ']'<< endl;
	}
}

AdyMatrix AdyMatrix::diferencia(vector<int>& v)
{
	AdyMatrix res(*this);
	for(int i = 0; i < (int)v.size(); i++)
	{
		for(int j = 0; j < nodesQ; j++)
		{
			res.matrix[v[i]][j] = 0;
			res.matrix[j][v[i]] = 0;
			edgesQ--;
		}
	}
	return res;
}

void AdyMatrix::erase(vector<int>& v)
{
	for(int i = 0; i < (int)v.size(); i++)
	{
		for(int j = 0; j < nodesQ; j++)
		{
			matrix[v[i]][j] = 0;
			matrix[j][v[i]] = 0;
			edgesQ--;
		}
	}
}


void AdyMatrix::add(vector<int>& v)
{
	//agregar todos las aristas entre todos los nodos de A
	for(int i = 0; i < (int)v.size() -1; i++)
	{
		for(int j = i+1; j < (int)v.size(); j++)
		{
			matrix[v[i]][v[j]] = 1;
			matrix[v[j]][v[i]] = 1;
			edgesQ++;
		}
	}
}

void AdyMatrix::add(AdyMatrix& M, int a)
{
	for(int i = 0; i < nodesQ; i++)
	{
		if(M.matrix[i][a] == 1)
		{
			matrix[i][a]=1;
			matrix[a][i]=1;
			edgesQ++;
		}
		matrix[a][a] = 0;
		M.matrix[a][a] = 0;
	}
}

void AdyMatrix::removeNode(int a)
{
	for(int i = 0; i < nodesQ; i++)
	{
		matrix[i][a]=0;
		matrix[a][i]=0;
	}
}

void AdyMatrix::grafoCompleto(){
	
	for(int i = 0; i < nodesQ; i++){
		for(int j=0;j<nodesQ;j++){

			if(j!=i){

				matrix[i][j]=1;
				matrix[j][i]=1;
			}

		}
	}
	
	edgesQ = nodesQ * (nodesQ-1);
	edgesQ /= 2;	
}


int AdyMatrix::aristas2()
{
	edgesQ = 0;
	for(int i = 0; i < nodesQ-1; i++)
	{
		for(int j = i+1; j < nodesQ; j++)
		{
			edgesQ += matrix[i][j];
		}
	}
	return edgesQ;
};


void AdyMatrix::shuffleViejo(){	//devuelve un grafo isomorfo al anterior

	for(int i = 0; i < nodesQ; i++){
		int target_node = i;
		while(target_node == i){
			target_node = rand() % nodesQ;	
		}

		//Swapeo fila
		vector<int> target_node_edges = matrix[target_node];
		vector<int> my_edges = matrix[i];
		matrix[i] = target_node_edges;
		matrix[target_node] = my_edges;

		//Swapeo columna 
		vector<int> target_node_edges_2;
		vector<int> my_edges_2;
		for(int j = 0; j< nodesQ; j++){
			target_node_edges_2.push_back(matrix[j][target_node]);
			my_edges_2.push_back(matrix[j][i]);
		}

		for(int j = 0; j< nodesQ; j++){
			matrix[j][target_node] = my_edges_2[j];
			matrix[j][i] = target_node_edges_2[j];
		}
	}
}


void AdyMatrix::shuffle()
{
	int o1, o2, d1, d2;

	int r = rand() % nodesQ/4;
	r++;
	while(r > 0)
	{
		r--;
		do
		{
			o1 = rand() % nodesQ;
			o2 = rand() % nodesQ;
			
		}while(o1 == o2);
		vector<int> arista1;
		vector<int> arista2;
		for(int i = 0; i < nodesQ; i++)
		{
			if(matrix[o1][i] == 1)
				arista1.push_back(i);
			if(matrix[o2][i] == 1)
				arista2.push_back(i);
		}
		
		do
		{
			d1 = rand() % arista1.size();
			
		}while(arista1[d1] == o2);
		d1 = arista1[d1];

		do
		{
			d2 = rand() % arista2.size();
			
		}while(arista2[d2] == o1 || arista2[d2] == d1);
		d2 = arista2[d2];

		matrix[o1][d1] = 0;
		matrix[o2][d2] = 0;
		matrix[o1][d2] = 1;
		matrix[o2][d1] = 1;
	}
}


int AdyMatrix::degree(int index){

	int count =0;
	for(int i=0; i<nodesQ;i++){
	
		if(matrix[index][i]==1){

			count ++;

		}


	}

	return count;

}


void AdyMatrix::removeEdge(int i1, int j2){

	matrix[i1][j2]=0;
	matrix[j2][i1]=0;

}

