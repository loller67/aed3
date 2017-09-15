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
		
	vector<int> azul(n,9999);
	vector<int> rojo(n,-9999);
	cout<<primer_caso(entrada,azul,-1,rojo,-1,0,0)<<endl;
	

	return 0;       
}


