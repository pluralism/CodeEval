#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;


int fib(int n)
{
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
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
		cout << fib(n) << endl;
	}
	return 0;
}