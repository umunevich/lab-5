#pragma once
#include <vector>
using namespace std;

class Matrix
{
	unsigned N = 5;
	vector<vector<int>> mat = vector<vector<int>>( N, vector<int>(N));
public:
	Matrix(unsigned, vector<vector<int>>);
	int get(const int& x, const int& y);
	int get_size();
};

