#ifndef _AUX_H_
#define _AUX_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <stdarg.h>
#include <utility>
#include <climits>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


/* ROJO ES CRECIENTE Y AZUL ES DECRECIENTE*/

using namespace std;
/*
struct tupla{
    int valor, pintado; //pintado es 1 o 0

    tupla(int n, bool e){
		valor=n;
		pintado=e;
		
		}
    tupla(){
		 valor =0;
		 pintado=false;
		 }
    
    tupla operator=(const tupla& v){
        valor = v.valor;
        pintado = v.pintado;
    }
};
*/



void imprimir_vector(vector<int> &vec, int n){

	for(int i=0;i<n;i++)
		cout<<vec[i]<< " ";
	cout<<" "<<endl;

}

void imprimir_matriz(vector<vector<int> > &vec,int n,int m){


	for(int i=0;i<n;i++){

	
		for(int j=0;j<m;j++){
			
			cout<<vec[i][j]<< " ";


		}

			cout<< " "<<endl;


	}

	cout<<" "<<endl;

}



//calcula la longitud de la subsec_crec mas larga y devuelve en first la longitud y en second el vector que se usa para armar las subsecuencias crecientes
int subsec_crec_aux(vector<int> &v,vector < pair <int,vector <int> > > &vec ){//o(n*n) 

	int max=0;
	vec[0].first=1; //inicializo la lista con longitud 1 y elemento anterior es -1

	vec[0].second.push_back(-1);
	for(int a=0;a<vec.size();a++){

		vec[a].first=1;

	}


	for(int i=1;i<v.size();i++){
		for(int j = 0;j<i;j++){ 
			if(v[i] > v[j] && vec[i].first -1 <= vec[j].first){
                		vec[i].first = vec[j].first + 1;//incremento cantidad
				vec[i].second.push_back(j);//me guardo indice del elemento anterior de la subsecuencia
			}
 		}
	}

	for (int k=0;k<vec.size();k++ ){
		if(max<vec[k].first){
			max = vec[k].first;

		}
	}
	/*int contador=0;

	for(int w=0;w<vec.size();w++){

		cout<<vec[w].first << " ";

	}
	cout<<" "<<endl;

	for (int l=0;l<vec.size();l++ ){
			imprimir_vector(vec[l].second,vec[l].second.size());
			if(max==vec[l].first)
			contador++;
		}
	cout<<" "<<endl;
	cout<<"contador"<<contador<<endl;*/
	
	return max;
}


//calcula la longitud de la subsec_decrec mas larga, de aca creo que no me interesa toda la solucion, solo el tamaño de la misma
int subsec_decrec_aux(vector<int> &v, vector<int> &indices){//o(n*n) 

	int max=0;
	vector <int>  vec(v.size(),-1);
	vec[0]=1; //inicializo la lista con longitud 1
	for(int a=0;a<vec.size();a++){

		vec[a]=1;

	}

	for(int i=1;i<v.size();i++){
		//if(indices[i]==0){//me fjio si el elemento esta sin pintar puedo chequear cosas, si esta pintado no hago nada
			for(int j = 0; j<i ;j++){ 
				if(v[j] > v[i] && vec[i]-1 <= vec[j]){
					vec[i] = vec[j] + 1;//incremento cantidad
				}
	 	//	}
		}
	}
		
	for (int k=0;k<vec.size();k++ ){
		if(max<vec[k]){
			max = vec[k];

		}
	}

	return max;

}
	


void f_rec(vector<int> &v ,vector < pair <int,vector <int> > > &vec, vector< vector<int> > &mat,int max,int m,int indice){

	if(max==0){//aca llegue al final
		return;

	}else{
		for(int i=vec[m].second.size()-1;m>=0;m--){

			if(vec[i].first==max){//si el elemento apunta a una subsecuencia creciente "maxima" 

				mat[indice][max-1]=i;	//me guardo su posicion	
				indice++;	
				f_rec(v,vec,mat,max-1,i,indice);	


			}



		}

	}


}

/*
La idea es obtener la longitud solucion maxima creciente, una vez hecho eso aprovecho la estructura del vector de tuplas para rearmar las soluciones maximas crecientes,
luego esas soluciones se guardan en una matriz, luego se carga otra matriz de indices con 1 si el iesimo elemento esta pintado para esa solucion maxima, de esta forma
en el doble for para buscar soluciones decrecientes no se agrega un for extra para mantener el o(n cuadrado) y que dicha funcion pueda ser llamada n veces.
De estas soluciones decrecientes se obtiene la de mayor longitud, se suma a la longitud creciente y luego se resta el largo del vector de entrada, dandonos la cantidad
de elementos sin pintar en o(n cubo)

*/
int buscar_crecientes(vector<int> &v ,vector < pair <int,vector <int> > > &vec){//o(n cubo)


	if(v.size()>2){

		int max = subsec_crec_aux(v,vec);// o(n*n) me guardo la longitud maxima creciente
		//cout<<max<<endl;
		//ahora debo rearmar las soluciones que tienen esa longitud, las guardo en una matriz
	   	vector< vector<int> > mat(v.size(), vector<int>(max));
		int max_temp= max;
		int indice_matriz=0;


		for(int l=0;l<v.size();l++){//busco los elementos que tienen cantidad max, esto tiene complejidad o(n*n*n) porque itero las n soluciones n veces para cada elemento de v en peor caso
	 

			if(vec[l].first==max){//si es el maximo pinto la columna que corresponde y llamo a la funcion recursiva 
				mat[indice_matriz][max-1]=l;
				for(int m=0;m<vec[l].second.size();m++){
					if(vec[m].first==max-1){
						mat[indice_matriz][max-2]=m;//guardo el segundo indice y llamo recursivo
						f_rec(v,vec,mat,max-1,m,indice_matriz);
						indice_matriz++;						
							
					}
				}


			}

		
		}



		//como la matriz que me queda es horrible, debo arreglarla

		if(max>1){
			for(int f=1;f<v.size();f++){//o(n*n)

				for(int c=max;c>0;c--){

					if(mat[f][c]==0){

						mat[f][c]=mat[f-1][c];

					}

				}

			}
	
		}

		//imprimir_matriz(mat,v.size(),v.size());

		//primero me guardo los indices de las soluciones en una matriz para poder accederlas en o(1) en subsec_decrec_aux

		vector< vector<int> > indices(v.size(), vector<int>(v.size()));

		for(int i=0;i<v.size();i++){//o(n*n)

			for(int j=0;j<max;j++){


				if(mat[i][j]!=-1){//si esta pintado lo marco

					indices[i][mat[i][j]]=1;

				}else{

					indices[i][mat[i][j]]=0;


				}

			}
		}


		//imprimir_matriz(indices,v.size(),v.size());


		//ahora que tengo en mat las soluciones crecientes, tengo que ver las soluciones decrecientes para cada solucion
		//para esto uso los indices que me guarde anteriormente


		int solucion_decr=0;

		for(int k=0;k<v.size();k++){//o(n* n cuadrado)= o(n cubo)

			int auxdec=subsec_decrec_aux(v,indices[k]);//o(n*n)
			//cout<<solucion_decr<<endl;
			if(auxdec>solucion_decr){
				solucion_decr=auxdec;

			}
		}
		//retorno la longitud del arreglo menos la solucion decreciente menos la solucion creciente, esto me da los elementos sin pintar
		return v.size()-solucion_decr-max;
	}else{

		return 0;

	}
}











#endif
