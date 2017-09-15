#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file_manager.h"


using namespace std;

void save_line(ofstream& my_file, string line){
	my_file << line << "\n";
}

void save_point(ofstream& my_file, int size, int time){
	string size_string = to_string(size);
	string time_string = to_string(time);
	string line = size_string + " " + time_string;
	save_line(my_file, line);
}

void save_vector(vector<int> times, int start, int end, int jumps, string file_name){
	//Open file
	ofstream my_file (file_name);

	int j = 0;
	for(int i = start; i <= end; i+= jumps){
		save_point(my_file, i, times[j]);
		j++;
	}

	//Close file
}