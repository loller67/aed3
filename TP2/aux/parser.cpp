#include "parser.h"
#include <iostream>
#include <math.h>

using namespace std;

//la idea es que llamen a las matrices de ady inicializadas vacias y se carguen aca
//otro dato de color es que el nodo "1" se guarda en la posicion 0, es decir el nodo i va en la posicion i-1

void getInputEj1(vector <vector < int > > &distancias, vector <vector < int > > &premium ){

	int n=0;//cantidad de ciudades
	int m=0;//cantidad de rutas

	cin >> n >> m;

	int origen=0;
	int destino=0;
	int k=0;// cantidad de rutas premium maxima

	cin >> origen >> destino >> k;

	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		distancias.push_back(row); // Add the row to the main vector
		premium.push_back(row); // Add the row to the main vector
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {

			distancias[x][y]=0;
			premium[x][y]=0;
		}
	}



	int c1=0;//ciudades
	int c2=0;
	int p=0;//premium o no la carretera
	int d=0;//distancia

	for(int i=0;i<m;i++){//levanto ciudades
		cin >> c1 >> c2 >> p >> d;

		distancias[c1-1][c2-1]=d;
		distancias[c2-1][c1-1]=d;
		premium[c1-1][c2-1]=p;
		premium[c2-1][c1-1]=p;

	}

}

void getInputEj2(vector <vector < int > > &ciudad){//aca directamente puede usarse una matriz de enteros

	int n=0;//cantidad de ciudades
	int m=0;//cantidad de rutas

	cin >> n >> m;

	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		ciudad.push_back(row); // Add the row to the main vector
	}


	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {

			ciudad[x][y]=0;
		}
	}


	int c1=0;//ciudades
	int c2=0;
	int p=0;//valor del peaje

	for(int i=0;i<m;i++){//levanto ciudades
		cin >> c1 >> c2 >> p;

		ciudad[c1-1][c2-1]=p;
		ciudad[c2-1][c1-1]=p;
	}

}

void getInputEj3(vector <vector < int > > &costo,int n){

	for (int j = 0; j < n; j++) {
		vector<int> row; // Create an empty row
		for (int l = 0; l < n; l++) {
			row.push_back(l * j); // Add an element (column) to the row
		}
		costo.push_back(row); // Add the row to the main vector
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			costo[x][y]=0;
		}
	}

	int c1=0;//ciudades
	int c2=0;
	int e=0;//e existe la ruta
	int p=0;//costo de construccion o destruccion

	for(int i=0;i<n*(n-1)/2;i++){//levanto ciudades
		cin >> c1 >> c2 >> e >> p;
		if(e==1){

			costo[c1-1][c2-1]=-p;
			costo[c2-1][c1-1]=-p;
		}else{

			costo[c1-1][c2-1]=p;
			costo[c2-1][c1-1]=p;
		}
	}
}
