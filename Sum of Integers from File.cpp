#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;
	int total = 0;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		total += atoi(line.c_str());
	}
	cout << total << endl;
	return 0;
}