
#include "../Estructura/Estructura.h"
#include "fixedNCases.h"
#include "data_manager.h"
#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include "fixedKCases.h"

using namespace std;

void run_performance_for_fixed_n_best_case(int limit, int jump_size,
		int fixed_n, int repetitions) {

	vector<int> tiempos;
	vector<int> cantidad_nodos;
	string file_name = "/home/joaquin/Desktop/Facultad/aed3tp21c2017/Ej1/Performance/Resultados/fixed_n_best_case";

	for(int i = 1; i < limit; i = i + jump_size){
		int n = fixed_n;
		//int m = 0;
		int k = i;
		int origen = 1;
		int destino = n;

		int total_time = 0;

		for(int a = 0; a < repetitions; a++){
			cout << "fixed n best case: " << i << endl << "Repeticion: " << a << endl;
			clock_t begin = clock();

			Estructura instancia = Estructura(k, n, origen, destino);
			instancia.resolver();

			clock_t end = clock();
			int elapsed_ticks = int(end - begin);
			total_time += elapsed_ticks;
		}

		tiempos.push_back(total_time / repetitions);
		cantidad_nodos.push_back(i);
	}

	save_data(cantidad_nodos, tiempos, file_name);
}


void run_performance_for_fixed_n_worst_case(int limit, int jump_size,
		int fixed_n, int repetitions) {

	vector<int> tiempos;
	vector<int> cantidad_nodos;
	string file_name = "/home/joaquin/Desktop/Facultad/aed3tp21c2017/Ej1/Performance/Resultados/fixed_n_worst_case";

	for(int i = 1; i < limit; i = i + jump_size){
		int n = fixed_n;
		//int m = n*(n-1)/2;
		int k = i;
		int origen = 1;
		int destino = n;

		int total_time = 0;

		for(int a = 0; a < repetitions; a++){
			cout << "fixed n worst case: " << i << endl << "Repeticion: " << a << endl;
			clock_t begin = clock();

			Estructura instancia = Estructura(k, n, origen, destino);

			for(int j = 0; j < n; j++){
				for(int k = 0; k<j; k++){
					if( j == k+1){
						instancia.conectar_nodos_con_ruta_comun(j+1,k+1,10);
						instancia.conectar_nodos_con_ruta_comun(k+1,j+1,10);
					}
					else{
						instancia.conectar_nodos_con_ruta_premium(j+1, k+1, 1);
						instancia.conectar_nodos_con_ruta_premium(k+1, j+1, 1);
					}
				}
			}

			instancia.resolver();

			clock_t end = clock();
			int elapsed_ticks = int(end - begin);
			total_time += elapsed_ticks;
		}
		tiempos.push_back(total_time / repetitions);
		cantidad_nodos.push_back(i);
	}

	save_data(cantidad_nodos, tiempos, file_name);
}


void run_performance_for_fixed_n_random_case(int limit, int jump_size,
		int fixed_n, int repetitions) {

	vector<int> tiempos;
	vector<int> cantidad_nodos;
	string file_name = "Resultados/fixed_n_random_case";

	for(int i = 1; i < limit; i = i + jump_size){
		int n = fixed_n;
		int k = i;
		int m = n*(n-1)/2;
		m = rand() %(m+1);
		int origen = 1;
		int destino = n;

		int total = 0;

		vector< vector<int> > ejes = hacer_ejes_random(n, m);

		for(int a = 0; a < repetitions; a++){
			cout << "fixed n random case: " << i << endl << "Repeticion: " << a << endl;

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
		cantidad_nodos.push_back(k);
	}

	save_data(cantidad_nodos, tiempos, file_name);
}
