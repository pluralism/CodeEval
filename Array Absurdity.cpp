#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line, line2;
		getline(fin, line, ';');
		int t = atoi(line.c_str());
		if (!line.empty())
		{
			int sum = 0;
			getline(fin, line2);
			replace(line2.begin(), line2.end(), ',', ' ');
			stringstream ss(line2);
			int N;
			while (ss >> N)
				sum += N;

			cout << sum - ((t - 2)*(t - 1) / 2) << endl;
		}
	}
	fin.close();
	return 0;
}