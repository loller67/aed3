
#include <fstream>
#include <vector>
#include <string>
#include "../Estructura/Estructura.h"
#include "../tools.h"

using namespace std;

int obtener_resultado(string filename){

	ifstream myfile (filename);
	vector<int> numeros = get_ints_grom_file(myfile);
	int sol = numeros[0];

	return sol;
}

void probar_caso(string file_name){

	string entrada = file_name + ".in";
	string salida = file_name + ".out";

	Estructura instancia = Estructura(entrada);

	int solucion_obtenida = instancia.resolver();
	int solucion_deseada = obtener_resultado(salida);

	if(solucion_obtenida != solucion_deseada){
		cout << "Caso: " << file_name << endl;
		cout << "Solucion obtenida: " << solucion_obtenida << endl;
		cout << "Solucion deseada: " << solucion_deseada << endl;
	}
	else{
		cout << "Prueba exitosa" << endl;
	}
}


int main(){

	string t1 = "dosCiudadesConectadasConCalleComun";
	string t2 = "dosCiudadesConectadasConCallePremium";
	string t3 = "dosCiudadesConectadasConCallePremiumYKEsCero";
	string t4 = "dosCiudadesConectadasConCallePremiumYKEsSuficiente";
	string t5 = "muchasCiudadesConSolucion";
	string t6 = "muchasCiudadesSinSolucion";

	probar_caso(t1);
	probar_caso(t2);
	probar_caso(t3);
	probar_caso(t4);
	probar_caso(t5);
	probar_caso(t6);

}


