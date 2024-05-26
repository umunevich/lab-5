#pragma once
#include <fstream>
#include <vector>
using namespace std;

void about();
void help_arg();
void end(vector<int> & vec_A, vector<int> & vec_B, vector<int> & task);

void open_file(ifstream& ifile, string& in);
void read_file(ifstream& ifile, vector<vector<int>>& vec_A, vector<vector<int>>& vec_B, int& N);
ofstream& operator<<(ofstream& ofile, const vector<int>& vec);