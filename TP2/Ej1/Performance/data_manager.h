#ifndef PERFORMANCE_DATA_MANAGER_H_
#define PERFORMANCE_DATA_MANAGER_H_

#include <vector>
#include <string>
#include <fstream>

using namespace std;

void save_data(vector<int> eje_x, vector<int> eje_y, string file_name);

void save_point(int x, int y, ofstream& file);



#endif
