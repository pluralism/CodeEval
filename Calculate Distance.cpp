#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<int> points;
		string line;
		getline(fin, line);
		if (line.empty())
			continue;

		for (int i = 0; i < line.size(); i++)
		if (!isdigit(line[i]) && line[i] != '-')
			replace(line.begin(), line.end(), line[i], ' ');

		stringstream ss(line);
		int i;
		while (ss >> i)
			points.push_back(i);

		cout << sqrt(pow(points[2] - points[0], 2) + pow(points[3] - points[1], 2)) << endl;
	}
	fin.close();
	return 0;
}