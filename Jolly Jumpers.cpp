#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


bool jolly(vector<int> numbers)
{
	bool first = true;
	int last_value = 0;
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		if (first)
			first = false;
		else {
			if (*it - last_value != 1)
				return false;
		}
		last_value = *it;
	}
	return true;
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		vector<int> numbers;
		vector<int> N;
		getline(fin, line);
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int num;
		bool got_n = false;
		while (ss >> num) {
			if (!got_n) {
				got_n = true;
			}
			else N.push_back(num);
		}
		if (N.size() == 1) {
			cout << "Jolly" << endl;
		}
		else {
			for (int i = 1; i < N.size(); i++)
			{
				int m = N[i] - N[i - 1];
				numbers.push_back(m < 0 ? -m : m);
			}
			sort(numbers.begin(), numbers.end());
			if (jolly(numbers))
				cout << "Jolly" << endl;
			else
				cout << "Not jolly" << endl;
		}
	}
	fin.close();
	return 0;
}
