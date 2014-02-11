#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;


int sum_of_number(int n)
{
	int total = 0;
	while (n)
	{
		total += n % 10;
		n /= 10;
	}

	return total;
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		int n;
		string line;
		getline(fin, line);
		n = atoi(line.c_str());
		cout << sum_of_number(n) << endl;
	}

	getchar();
	return 0;
}