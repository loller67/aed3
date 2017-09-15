#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include "../aux/AdyacencyList/AdyacencyList.h"
#include "../aux/parser.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <utility>
#include <climits>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


void imprimir_vector(vector<int> &origen ,vector<int> &destino , int n){

	for(int i=0;i<n;i++){
		std::cout << "(";
		cout<<origen[i]+1<< ",";
		std::cout << destino[i]+1 << ") ";
		}

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



#endif
