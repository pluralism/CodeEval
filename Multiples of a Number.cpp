#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		int x, n;

		getline(fin, line);
		replace(line.begin(), line.end(), ',', ' ');
		string tmp;
		stringstream ss(line);
		while (ss >> x >> n)
		{
			for (int i = 1;; i++)
			{
				if (n * i >= x)
				{
					cout << n * i << endl;
					break;
				}
			}
		}

	}
	fin.close();
	return 0;
}