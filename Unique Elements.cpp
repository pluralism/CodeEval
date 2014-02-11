#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);

	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		set<int> numbers;
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		string s;
		while (ss >> s)
			numbers.insert(atoi(s.c_str()));

		int i = 0;
		for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		{
			if (i != numbers.size() - 1)
				cout << *it << ",";
			else
				cout << *it << endl;
			i++;
		}
	}
	fin.close();
	return 0;
}