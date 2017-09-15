#ifndef PERFORMANCE_FIXEDKCASES_H_
#define PERFORMANCE_FIXEDKCASES_H_

#include <vector>

using namespace std;

void run_performance_for_fixed_k_best_case(int limit, int jump_size,
		int fixed_k, int repetitions);

void run_performance_for_fixed_k_worst_case(int limit, int jump_size,
		int fixed_k, int repetitions);

void run_performance_for_fixed_k_random_case(int limit, int jump_size,
		int fixed_k, int repetitions);

vector< vector<int> > hacer_ejes_random(int n, int m);

#endif
