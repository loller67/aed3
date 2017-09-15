#include "aux.h"

int main(){

	int elem=0;
	int n=0;
	cin>>n;
	vector <int> entrada(n);
	
	for(int i=0;i<n;i++){
		cin>>elem;
		entrada[i]=elem;	
	}
		

	vector < pair <int,vector <int> > > vec(entrada.size());// el primer elemento del vector es la longitud hasta ese elemento de la secuencia creciente
	//el segundo elemento es el vector de todos sus elementos anteriores qeu se va a usar para calcular las subsecuencias crecientes maximas

	//retorno la cantidad de elementos sin pintar
	cout<<buscar_crecientes(entrada,vec)<<endl;

	

	


	return 0;



}


