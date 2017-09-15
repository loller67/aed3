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
		

	cout<<primer_caso(entrada)<<endl;

	

	


	return 0;



}


