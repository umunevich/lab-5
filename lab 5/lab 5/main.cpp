#include "Matrix.h"
#include "inoutput.h"
#include "walk.h"
#include <iostream>
#include <fstream>
using namespace std;
void procc_arg(int& argc, char* argv[], string& in, string& out)
{
	
	if (argc < 3)
	{
		help_arg();
		exit(0);
	}
	else
	{
		in = argv[1];
		out = argv[2];
		cout << "Input file path: '" << in << "'\n";
		cout << "Output file path: '" << out << "'\n";
	}
}

int main(int argc, char* argv[])
{	
	about();
	string in;
	string out;
	procc_arg(argc, argv, in, out);
	ifstream ifile;
	ofstream ofile;

	open_file(ifile, in);
	ofile.open(out, ofstream::out);
	
	int N = 0;
	if (!(ifile >> N) || N < 4)
	{
		try
		{
			throw invalid_argument("WRONG SIZE INPUT.");
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
			exit(0);
		}
	}
	vector<vector<int>> vec_A = vector<vector<int>>(N, vector<int>(N));
	vector<vector<int>> vec_B = vector<vector<int>>(N, vector<int>(N));
	read_file(ifile, vec_A, vec_B, N);
	ifile.close();
	Matrix matrix_A(N, vec_A);
	Matrix matrix_B(N, vec_B);

	vector<int> answear_A = traversal_A(matrix_A);
	vector<int> answear_B = traversal_B(matrix_B);
	vector<int> task = min(answear_A, answear_B);
	end(answear_A, answear_B, task);
	ofile << task;
	ofile.close();
}