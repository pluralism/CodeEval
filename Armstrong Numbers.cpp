#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		int N = line.size();
		int total = 0;
		for (int i = 0; i < line.size(); i++)
			total += pow(line[i] - '0', N);

		if (total != atoi(line.c_str()))
			cout << "False" << endl;
		else
			cout << "True" << endl;
	}
	fin.close();

	return 0;
}