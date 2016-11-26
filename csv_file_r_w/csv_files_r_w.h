#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
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

#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::atoi;
using std::endl;

vector<string> csvrw_file_reading(string file_path);
void csvrw_file_writing(string file_path, vector<vector<int>> csv_file);

vector < vector <int> > csvrw_reading_and_format(string file_path);