#include "aux.h"


//escribe en formato texto los elementos crecientes
void testCreciente(int tamano){

	for(int i=1;i<=tamano;i++){

		cout<<i<<endl;
		for(int j=1;j<=i;j++){

			cout<<j<<" ";
			if(j==i){

				cout<<""<<endl;
			}

	}


	}


}
//escribe en formato texto los elementos decrecientes
void testDecreciente(int tamano){

	for(int i=1;i<=tamano;i++){

		cout<<i<<endl;
		for(int j=i;j>=1;j--){

			cout<<j<<" ";
			if(j==1){

				cout<<""<<endl;
			}

	}

	}


}

void generadorDeCreciente(int n){

	clock_t t_ini, t_fin;
	double secs;
	vector <int> entrada(n+1);
	for(int i=n;i>0;i--){
		
		entrada[i]=i;	

	}

	vector < pair <int,vector <int> > > vec(entrada.size());
	t_ini = clock();
	cout<<buscar_crecientes(entrada,vec);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout<< n <<" ";
	printf("%.16g ", secs * 1000.0);
	cout<< ""<<endl;



}

void llamar_a_generador_decrec(int n){

	for(int i=0;i<n;i++){

		generadorDeCreciente(i);


	}

}



void generadorCreciente(int n){

	clock_t t_ini, t_fin;
	double secs;
	vector <int> entrada(n+1);
	for(int i=0;i<n;i++){
		
		entrada[i]=i+1;		
	}

	
	vector < pair <int,vector <int> > > vec(entrada.size());
	t_ini = clock();
	buscar_crecientes(entrada,vec);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout<< n <<" ";
	printf("%.16g ", secs * 1000.0);
	cout<< ""<<endl;

}

void llamar_a_generador_crec(int n){

	for(int i=0;i<n;i++){

		generadorCreciente(i);


	}

}

//peor caso, todos los elementos repetidos
void generadorPeor(int n){

	clock_t t_ini, t_fin;
	double secs;
	vector <int> entrada(n+1);
	int max=n;
	int min=1;	
	for(int i=0;i<n;i++){
		
		if(i % 2==0){		
			entrada[i]=max;
			max--;
		}else{
			entrada[i]=min;
			min++;

		}

	}
	vector < pair <int,vector <int> > > vec(entrada.size());
	t_ini = clock();
	buscar_crecientes(entrada,vec);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout<< n <<" ";
	printf("%.16g ", secs * 1000.0);
	cout<< ""<<endl;

}

void llamar_a_generador_peor(int n){

	for(int i=0;i<n;i++){

		generadorPeor(i);


	}

}





//mejor caso, todos los elementos repetidos
void generadorMejor(int n, int k){

	clock_t t_ini, t_fin;
	double secs;
	vector <int> entrada(n+1);
	
	for(int i=0;i<n;i++){
		entrada[i]=k;	
	}
	vector < pair <int,vector <int> > > vec(entrada.size());
	t_ini = clock();
	buscar_crecientes(entrada,vec);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;

	cout<< n <<" ";
	printf("%.16g ", secs * 1000.0);
	cout<< ""<<endl;
}

void llamar_a_generador_mejor(int n){

	for(int i=0;i<n;i++){

		generadorMejor(i,10);


	}

}

// generador de instancias aleatorias
void generadorRandom(int n){


	clock_t t_ini, t_fin;
	double secs;
	vector <int> entrada(n+1);
	
	for(int i=0;i<n;i++){
		entrada[i]=rand()+1;	
	}
	vector < pair <int,vector <int> > > vec(entrada.size());
	t_ini = clock();
	buscar_crecientes(entrada,vec);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout<< n <<" ";
	printf("%.16g ", secs * 1000.0);
	cout<< ""<<endl;
}

void llamar_a_generador_random(int n){

	for(int i=0;i<n;i++){

		generadorRandom(i);


	}

}

int main(){
	cout<<"mejor"<<endl;
	llamar_a_generador_mejor(501);
	cout<< ""<<endl;
	cout<<"random"<<endl;
	llamar_a_generador_random(501);
	cout<< ""<<endl;
	cout<<"peor"<<endl;
	llamar_a_generador_peor(501);
	cout<< ""<<endl;
	cout<<"crec"<<endl;
	llamar_a_generador_crec(501);
	cout<< ""<<endl;
	cout<<"decrec"<<endl;
	llamar_a_generador_decrec(501);

	return 0;
}


