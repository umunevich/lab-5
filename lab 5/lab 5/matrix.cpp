#include "matrix.h"

Matrix::Matrix(unsigned N_, vector<vector<int>> mat_) : N(N_), mat(move(mat_)) {}

int Matrix::get(const int& x,const int& y)
{
	return this->mat[x][y];
}
int Matrix::get_size()
{
	return this->N;
}