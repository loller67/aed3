#ifndef PERFORMANCE_FIXEDNCASES_H_
#define PERFORMANCE_FIXEDNCASES_H_

using namespace std;

void run_performance_for_fixed_n_best_case(int limit, int jump_size,
		int fixed_n, int repetitions);

void run_performance_for_fixed_n_worst_case(int limit, int jump_size,
		int fixed_n, int repetitions);

void run_performance_for_fixed_n_random_case(int limit, int jump_size,
		int fixed_n, int repetitions);

#endif
