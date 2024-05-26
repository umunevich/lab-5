#include "inoutput.h"
#include <fstream>
#include <iostream>
using namespace std;

void about()
{
	cout << "         Yana Utochkina, K - 13" << endl;
	cout << "    Variant 74. Operation: minimum. Sequence 1 is traversing by maximum\n";
	cout << "  points in each bottom section row from bottom to top (matrix A). Sequence 2\n";
	cout << "  is traversing by maximum points in each right-bottom corner column from\n";
	cout << "  right to left (matrix B). \n" << endl;
}

void help_arg()
{
	cout << "Usage \"lab 5.exe\" INPUT_FILE OUTPUT_FILE\n";
}

void end(vector<int>& vec_A, vector<int>& vec_B, vector<int>& task)
{
	cout << "DEBUG X = ";
	for (auto it = vec_A.begin(); it < vec_A.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << '\n';
	cout << "DEBUG Y = ";
	for (auto it = vec_B.begin(); it < vec_B.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << '\n';
	cout << "DEBUG S = ";
	for (auto it = task.begin(); it < task.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << '\n';
	cout << "\nBye)\n";
}

void open_file(ifstream& ifile, string& in)
{
	ifile.open(in, ifstream::in);
	try
	{
		if (!(ifile.is_open()))
		{
			throw invalid_argument("WRONG INPUT FILE PATH.");
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		exit(0);
	}
}

/*
	Read file and write data in 2d vector.
*/
void read_file(ifstream& ifile, vector<vector<int>>& vec_A, vector<vector<int>>& vec_B, int& N)
{
	try
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!(ifile >> vec_A[i][j]))
				{
					throw invalid_argument("WRONG INPUT.");
				}

			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!(ifile >> vec_B[i][j]))
				{
					throw invalid_argument("WRONG INPUT.");
				}
			}
		}
		if (ifile >> vec_A[0][0])
		{
			throw invalid_argument("INVALID MATRIX SIZE.");
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		exit(0);
	}
}

ofstream& operator<<(ofstream& ofile, const vector<int>& vec)
{
	for (auto it = vec.begin(); it < vec.end(); it++)
	{
		ofile << *it << ' ';
	}
	return ofile;
}