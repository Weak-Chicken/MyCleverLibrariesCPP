/*
@author: Yucheng Xie

Version 1.0 - Date: 11/25/2016:
Build reading, writing, reading and formating functions.

Copyright © 2016 Yucheng Xie. All rights reserved.
*/

/*
Bug:
Cannot be used on irregular csv file.
*/

#include "csv_files_r_w.h"

vector<string> csvrw_file_reading(string file_path)
{
	string line;
	ifstream this_file(file_path);
	vector<string> results;

	if(this_file.is_open()) {
		while(getline(this_file, line)) {
			results.push_back(line);
		}
		this_file.close();
	}
	else {
		cout << "Unable to open file";
	}

	return results;
}

void csvrw_file_writing(string file_path, vector<vector<int>> csv_file)
{
	ofstream this_file(file_path);
	if(this_file.is_open())
	{
		for (int i = 0;i < csv_file.size();i++) {
			for (int j = 0;j < csv_file[i].size();j++) {
				this_file << csv_file[i][j];
				if (j != csv_file[i].size() - 1) {
					this_file << ",";
				}
			}
			this_file << endl;
		}
	}
	else {
		cout << "Unable to open file";
	}
	this_file.clear();
	this_file.close();
}

vector<vector<int>> csvrw_reading_and_format(string file_path)
{
	vector <string> temp_string = csvrw_file_reading(file_path);
	vector <int> temp_int;
	vector<vector<int>> results;

	for (int i = 0;i < temp_string.size();i++) {
		while (temp_string[i].find(",") != std::string::npos) {
			temp_int.push_back(atoi(temp_string[i].substr(0,temp_string[i].find(",")).c_str()));
			temp_string[i] = temp_string[i].substr(temp_string[i].find(",") + 1);
		}
		temp_int.push_back(atoi(temp_string[i].c_str()));
		results.push_back(temp_int);
		temp_int.clear();
	}

	return results;
}
