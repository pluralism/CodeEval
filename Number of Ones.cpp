#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		int N = atoi(line.c_str());
		int total = 0;
		while (N)
		{
			if (N & 1)
				total++;
			N >>= 1;
		}
		cout << total << endl;
	}
	return 0;
}

