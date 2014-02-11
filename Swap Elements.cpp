#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


/**
* Keep in mind that this will only work if it's guaranteed
* that the list of numbers to swap is well formatted and in pairs!
*/
int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<int> numbers;
		string line;
		getline(fin, line, ':');
		stringstream ss(line);
		string tmp;
		while (ss >> tmp)
			numbers.push_back(atoi(tmp.c_str()));
		string line2;
		getline(fin, line2);
		replace(line2.begin(), line2.end(), '-', ' ');
		replace(line2.begin(), line2.end(), ',', ' ');
		stringstream ss2(line2);
		string st, nd;
		while (ss2 >> st)
		{
			ss2 >> nd;
			swap(numbers[atoi(st.c_str())], numbers[atoi(nd.c_str())]);
		}

		for (size_t i = 0; i < numbers.size(); i++)
		{
			if (i != numbers.size() - 1)
				cout << numbers[i] << " ";
			else
				cout << numbers[i] << endl;
		}
	}
	fin.close();
	return 0;
}