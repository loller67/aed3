
#include "../Estructura/Estructura.h"
#include "fixedKCases.h"
#include "data_manager.h"
#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void run_performance_for_fixed_k_best_case(int limit, int jump_size,
		int fixed_k, int repetitions) {

	vector<int> tiempos;
	vector<int> cantidad_nodos;
	string file_name = "/home/joaquin/Desktop/Facultad/aed3tp21c2017/Ej1/Performance/Resultados/fixed_k_best_case";

	for(int i = 1; i < limit; i = i + jump_size){
		int n = i;
		//int m = 0;
		int k = fixed_k;
		int origen = 1;
		int destino = n;

		int total_time = 0;

		for(int a = 0; a< repetitions; a++){
			cout << "fixed k best case: " << i << endl << "Repeticion: " << a << endl;
			clock_t begin = clock();

			Estructura instancia = Estructura(k, n, origen, destino);
			instancia.resolver();

			clock_t end = clock();
			int elapsed_ticks = int(end - begin);
			total_time += elapsed_ticks;
		}
		tiempos.push_back(total_time / repetitions);
		cantidad_nodos.push_back(n);
	}

	save_data(cantidad_nodos, tiempos, file_name);
}


void run_performance_for_fixed_k_worst_case(int limit, int jump_size,
		int fixed_k, int repetitions) {

	vector<int> tiempos;
	vector<int> cantidad_nodos;
	string file_name = "Resultados/fixed_k_worst_case";

	for(int i = 1; i < limit; i = i + jump_size){
		int n = i;
		//int m = n*(n-1)/2;
		int k = fixed_k;
		int origen = 1;
		int destino = n;

		int total = 0;

		for(int a = 0; a < repetitions; a++){
			cout << "fixed k worst case: " << i << endl;
			cout << "Repeticion: " << a << endl;

			clock_t begin = clock();

			Estructura instancia = Estructura(k, n, origen, destino);

			for(int j = 0; j < n; j++){

				for(int h = 0; h<j; h++){

					if( j == h+1){
						instancia.conectar_nodos_con_ruta_comun(j+1,h+1,10);
						instancia.conectar_nodos_con_ruta_comun(h+1,j+1,10);
					}
					else{


						instancia.conectar_nodos_con_ruta_premium(j+1, h+1, 1);
						instancia.conectar_nodos_con_ruta_premium(h+1, j+1, 1);

					}
				}
			}

			instancia.resolver();

			clock_t end = clock();
			int elapsed_ticks = int(end - begin);
			total += elapsed_ticks;

		}
		tiempos.push_back(total / repetitions);
		cantidad_nodos.push_back(n);
	}

	save_data(cantidad_nodos, tiempos, file_name);
}

void run_performance_for_fixed_k_random_case(int limit, int jump_size,
		int fixed_k, int repetitions) {

	vector<int> tiempos;
	vector<int> cantidad_nodos;
	string file_name = "/home/joaquin/Desktop/Facultad/aed3tp21c2017/Ej1/Performance/Resultados/fixed_k_random_case";

	for(int i = 1; i < limit; i = i + jump_size){
		int n = i;
		int m = n*(n-1)/2;
		m = rand() %(m+1);
		int k = fixed_k;
		int origen = 1;
		int destino = n;

		int total = 0;

		vector< vector<int> > ejes = hacer_ejes_random(n, m);

		for(int a = 0; a < repetitions; a++){
			cout << "fixed k random case: " << i << endl << "Repeticion: " << a << endl;

			clock_t begin = clock();

			Estructura instancia = Estructura(k, n, origen, destino);

			for(int i = 0; i < (int) ejes.size(); i++){
				vector<int> eje = ejes[i];
				if( eje[0] == 0){
					instancia.conectar_nodos_con_ruta_comun(eje[1]+1,eje[2]+1,10);
					instancia.conectar_nodos_con_ruta_comun(eje[2]+1,eje[1]+1,10);
				}
				else{
					instancia.conectar_nodos_con_ruta_premium(eje[1]+1, eje[2]+1, 1);
					instancia.conectar_nodos_con_ruta_premium(eje[2]+1, eje[1]+1, 1);
				}

			}

			instancia.resolver();

			clock_t end = clock();
			int elapsed_ticks = int(end - begin);
			total += elapsed_ticks;
		}
		tiempos.push_back(total / repetitions);
		cantidad_nodos.push_back(n);
	}

	save_data(cantidad_nodos, tiempos, file_name);
}

vector< vector<int> > hacer_ejes_random(int n, int m){
	vector< vector <int > > solucion;

	vector< vector<int > > todos_los_ejes;

	for(int i = 0; i < n; i++){
		for(int j = 0; j<i; j++){
			vector<int> eje;
			eje.push_back(i);
			eje.push_back(j);
			todos_los_ejes.push_back(eje);
		}
	}

	random_shuffle( todos_los_ejes.begin(), todos_los_ejes.end() );

	for(int i = 0; i < m; i++){
		int es_premium = rand() % 2;
		vector<int> eje = todos_los_ejes[i];
		int a = eje[0];
		int b = eje[1];
		vector<int> datos;
		datos.push_back(es_premium);
		datos.push_back(a);
		datos.push_back(b);
		solucion.push_back(datos);
	}

	return solucion;
}

