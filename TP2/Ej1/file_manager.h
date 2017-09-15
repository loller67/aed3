#ifndef _file_manager_h_
#define _file_manager_h_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void save_line(ofstream& my_file, string line);

void save_point(ofstream& my_file, int size, int time);

void save_vector(vector<int> times, int start, int end, int jumps, string file_name);



#endif