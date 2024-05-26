#include "walk.h"

vector<int> traversal_A(Matrix & mat)
{
	int N = mat.get_size();
	int k = 1;
	if (N % 2 == 1)
	{
		k = 0;
	}
	int max = 0;
	int a = 0;
	vector<int> temp{};
	for (int j = 0; j < N / 2 + 1 - k; j++)
	{
		for (int i = a; i < N - a; i++)
		{
			if (mat.get(N-1-j, i) > max)
			{
				max = mat.get(N - 1 - j, i);
			}
		}
		a++;
		temp.push_back(max);
		max = 0;
	}
	return temp;
}

vector<int> traversal_B(Matrix& mat)
{
	int N = mat.get_size();
	int k = 1;
	if (N % 2 == 1)
	{
		k = 0;
	}
	int max = 0;
	int a = N / 2 - 1 + k;
	vector<int> temp{};
	for (int j = 0; j < N / 2 + 1 - k; j++)
	{
		for (int i = 0; i < N - 1 - a; i++)
		{
			if (mat.get(N-1-i, N-1-j) > max)
			{
				max = mat.get(N - 1 - i, N - 1 - j);
			}
		}
		a--;
		temp.push_back(max);
		max = 0;
	}
	return temp;
}

vector<int> min(vector<int>& a, vector<int>& b)
{
	vector<int> temp{};
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i])
		{
			temp.push_back(b[i]);
		}
		else
		{
			temp.push_back(a[i]);
		}
	}
	return temp;
}