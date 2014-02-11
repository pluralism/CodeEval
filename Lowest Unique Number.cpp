#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		map<int, int> numbers;
		vector<int> non_repeated;
		string line;
		getline(fin, line);
		stringstream ss(line);
		string tmp;
		while (ss >> tmp)
			numbers[atoi(tmp.c_str())]++;

		for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		{
			if (it->second == 1)
				non_repeated.push_back(it->first);
		}
		if (non_repeated.size() != 0)
		{
			sort(non_repeated.begin(), non_repeated.end());
			int pos = 0;
			stringstream ss2(line);
			while (ss2 >> tmp)
			{
				if (atoi(tmp.c_str()) == non_repeated[0])
				{
					cout << pos + 1 << endl;
					break;
				}
				else pos++;
			}
		}
		else cout << "0" << endl;
	}
	fin.close();
	return 0;
}