

#include "Estructura/Estructura.h"
#include "standard_input_manager.h"
#include "tools.h"
#include <vector>
#include <iostream>


using namespace std;

int main(){

	vector<int> resultados;

	string line;

	getline(cin, line);
	vector<int> first_line = string_to_ints(line);
	int n = first_line[0];
	int m = first_line[1];
	while(n != -1){


		getline(cin, line);
		vector<int> second_line = string_to_ints(line);
		int origen = second_line[0];
		int destino = second_line[1];
		int k = second_line[2];

		Estructura instancia = Estructura(k, n, origen, destino);

		for(int i = 0; i < m; i++){
			getline(cin, line);
			vector<int> tmp = string_to_ints(line);
			int c1 = tmp[0];
			int c2 = tmp[1];
			int p = tmp[2];
			int d = tmp[3];

			if(p == 1){
				instancia.conectar_nodos_con_ruta_premium(c1, c2, d);
			}
			else{
				instancia.conectar_nodos_con_ruta_comun(c1, c2, d);	
			}
		}

	
		int solucion = instancia.resolver();
		resultados.push_back(solucion);

		getline(cin, line);
		first_line = string_to_ints(line);
		n = first_line[0];
		m = first_line[1];
	}

	for(int i = 0; i < (int) resultados.size(); i++){
		cout << resultados[i] << endl;
	}
}



