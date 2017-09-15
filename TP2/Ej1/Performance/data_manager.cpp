
#include "data_manager.h"
#include <vector>
#include <string>
#include <fstream>


using namespace std;


void save_data(vector<int> eje_x, vector<int> eje_y, string file_name){

	ofstream file(file_name);

	for(int i = 0; i< (int) eje_x.size(); i++){
		int x = eje_x[i];
		int y = eje_y[i];

		save_point(x, y, file);
	}
}

void save_point(int x, int y, ofstream& file) {
	file << x << " " << y << endl;
}

