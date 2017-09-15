#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

string read_line_from_file(istream& myfile);

string read_line_from_standar_input();

vector<int> string_to_ints(string& str);

vector<int> get_ints_grom_standar_input();

vector<int> get_ints_grom_file(istream& myfile);

void print_vector(vector<int> vector);

istream& open_file(string file_name);

#endif