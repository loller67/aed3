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

void f_rec(vector<int> &v,vector< vector<int> > &mat, int f, int c){// C ES ROJO Y F ES AZUL

	int res = 0;

	if(f==c){

		for(int i=1;i<v.size();i++){

			if(mat[i][c]>-1){

				res=max(mat[i][c],res);

			}else{

				f_rec(v,mat,i,c);
				res=max(mat[i][c],res);

			}

		}
		for(int j=1;j<v.size();j++){

			if(mat[f][j]>-1){

				res=max(mat[f][j],res);

			}else{
				f_rec(v,mat,f,j);
				res=max(mat[f][j],res);

			}

		}
		if(mat[f+1][f+1]  == -1){ 

			f_rec(v,mat,f+1,f+1);
		}

		res=max(mat[f+1][f+1],res);
		mat[f][c]=res+1;

	}else{
		if(c==v.size()){
			
			res=0;
				
			for(int k=f+1;k<v.size();k++){
				if(k!=v.size()){
					if(mat[k][c]==-1){
						f_rec(v,mat,k,c);
					}
					
					res=max(res,mat[k][c]);
				}
			}
			mat[f][c]=res+1;	
		}
		if(f==v.size()){
			
			res = 0;
				
			for(int k=c+1;k<v.size();k++){
				if(k!=v.size()){
					if(mat[f][k]==-1){
						f_rec(v,mat,f,k);
					}
					
					res=max(res,mat[f][k]);
				}
			}
			mat[f][c]=res+1;	
		}

		if(min(f,c)==f && c!=v.size() && f!=v.size() ){//fijo c

			if(mat[v.size()][c]==-1){

				f_rec(v,mat,v.size(),c);

			}

			res = mat[v.size()][c];
		
			for(int k=f+1;k<v.size();k++){

				if(v[k]<v[f]){

					if(mat[k][c]==-1){
						f_rec(v,mat,k,c);
					}
						
					res=max(res,mat[k][c]);


				}

			}
			mat[f][c]=res+1;


		}else{// caso min(f,c)=c y fijo f 
			if( c!=v.size() && f!=v.size()){
			
				if(mat[f][v.size()]==-1){

					f_rec(v,mat,f,v.size());

				}

				res = mat[f][v.size()];
				
				for(int k=c+1;k<v.size();k++){

					if(v[k]>v[c]){

						if(mat[f][k]==-1){
							f_rec(v,mat,f,k);
						}
						
						res=max(res,mat[f][k]);


					}

				}
				mat[f][c]=res+1;
				}
		}		


	}


}

int primer_caso(vector<int> &v){// C ES ROJO Y F ES AZUL

	vector< vector<int> > mat(v.size()+1, vector<int>(v.size()+1,-1));
	mat[v.size()][v.size()]=0;
	f_rec(v,mat,0,0);
	int res= mat[0][0];

	return v.size()-res;
}

#endif
