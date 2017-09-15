#include "AdyMatrix.h"
#include <assert.h>     /* assert */

//using namespace std;

AdyMatrix::AdyMatrix(){
	edgesQ = 0;
	nodesQ = 0;
	matrix = vector<vector<int> >(1, vector<int>(1));
}

AdyMatrix::AdyMatrix(int n){
	nodesQ = n;
	matrix = vector<vector<int> >(n, vector<int>(n,0));
}

AdyMatrix::AdyMatrix(int n, int k){
	nodesQ = n;
	matrix = vector<vector<int> >(n, vector<int>(n,k));	
}

AdyMatrix::~AdyMatrix() {
}

void AdyMatrix:: set(int i,int j,int val){
		
		if(i<nodesQ || j<nodesQ){
			
			
			matrix[i][j]=val;
			
			}
		
		}
		
		
int AdyMatrix:: get (int i,int j){
		
		return matrix[i][j];
		
		}



void AdyMatrix::addEdge(int n1, int n2){

		//assert(n1==n2);
		//assert(matrix[n1][n2]>=1 ||matrix[n2][n1]>=1);
		matrix[n1][n2]=1;
		matrix[n2][n1]=1;

}

void AdyMatrix::addEdge(int n1, int n2, int w){

		//assert(n1==n2);
		//assert(matrix[n1][n2] ||matrix[n2][n1]);
		matrix[n1][n2]=w;
		matrix[n2][n1]=w;


}

void AdyMatrix::print(){
	for(int i = 0; i < nodesQ; i++){
		for(int j=0;j<nodesQ;j++){
			if(j==nodesQ-1){
				cout <<"["<< matrix[i][j]<<"]" << endl;
				}
				else{
				
					cout <<"["<< matrix[i][j]<<"]" ;

				
				}
		}
	}
	
};
