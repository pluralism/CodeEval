#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<int> set1;
		vector<int> set2;
		vector<int>::iterator it;
		string line;
		getline(fin, line, ';');
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		string tmp;
		while (ss >> tmp)
			set1.push_back(atoi(tmp.c_str()));
		getline(fin, line);
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss2(line);
		while (ss2 >> tmp)
			set2.push_back(atoi(tmp.c_str()));

		vector<int> inter(set1.size() + set2.size() + 1);
		it = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inter.begin());
		inter.resize(it - inter.begin());
		if (inter.size() == 0)
			cout << endl;
		else
		for (int i = 0; i < inter.size(); i++)
		{
			if (i != inter.size() - 1)
				cout << inter[i] << ",";
			else
				cout << inter[i] << endl;
		}
	}
	fin.close();

	return 0;
}