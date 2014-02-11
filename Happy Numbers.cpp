#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;


int sum_n(int n)
{
	int total = 0;
	while (n)
	{
		total += pow(n % 10, 2);
		n /= 10;
	}

	return total;
}


int eval_num(int N, int i)
{
	if (i > 1000)
		return 0;
	else if (sum_n(N) == 1)
		return 1;
	else eval_num(sum_n(N), i + 1);
}

int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		int N;
		fin >> N;
		fin.ignore();

		cout << eval_num(N, 0) << endl;
	}
	fin.close();
	return 0;
}
