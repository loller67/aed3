
#include "../Estructura/Estructura.h"
#include <iostream>
#include "fixedKCases.h"
#include "fixedNCases.h"

using namespace std;


int main(){

	int fixed_n = 100;
	int fixed_k = 100;
	int max_n = 505;
	int max_k = 505;
	int jumps = 25;
	int repetitions = 10;


	cout << "fixed k best case" << endl;
	run_performance_for_fixed_k_best_case(max_n, jumps, fixed_k, repetitions);

	cout << "fixed k worst case" << endl;
	run_performance_for_fixed_k_worst_case(max_n, jumps, fixed_k, repetitions);

	cout << "fixed n best case" << endl;
	run_performance_for_fixed_n_best_case(max_k, jumps, fixed_n, repetitions);

	cout << "fixed n worst case" << endl;
	run_performance_for_fixed_n_worst_case(max_k, jumps, fixed_n, repetitions);



	cout << "fixed k random case" << endl;
	run_performance_for_fixed_k_random_case(max_n, jumps, fixed_k, repetitions);

	cout << "fixed n random case" << endl;
	run_performance_for_fixed_n_random_case(max_k, jumps, fixed_n, repetitions);


}










