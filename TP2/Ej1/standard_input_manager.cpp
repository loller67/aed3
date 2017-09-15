
#include <iostream>
#include <vector>
#include <string>
#include "standard_input_manager.h"

using namespace std;


string get_line(){
	string line;
	getline(cin, line);
	return line;
}

vector<string> get_multiple_lines(int number_of_lines){
	vector<string> lines;
	for(int i = 0; i < number_of_lines; i++){
		string line = get_line();
		lines.push_back(line);
	}
	return lines;
}
