#include "tools.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void print_vector(vector<int> vector){
	for(int i = 0; i < (int) vector.size(); i++){
		cout << vector[i] << " ";
	}
	cout << endl;
}

string read_line_from_file(ifstream& myfile){
	string line;
	getline (myfile,line);
	return line;
}

string read_line_from_standar_input(){
	string line;
	getline (cin,line);
	return line;
}

vector<int> string_to_ints(string& str){
	stringstream parse(str);
	vector<int> vector_res;

	int number;
	while(parse >> number){
		vector_res.push_back( number );
	}

	return vector_res;
}

vector<int> get_ints_grom_standar_input(){
	string str = read_line_from_standar_input();
	return string_to_ints(str);
}

vector<int> get_ints_grom_file(ifstream& myfile){
	string str = read_line_from_file(myfile);
	return string_to_ints(str);
}


