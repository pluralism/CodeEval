#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty()) continue;
		vector<int> numbers;
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int N;
		while (ss >> N)
			numbers.push_back(N);
		int max_sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			int cur_sum = 0;
			for (int j = i; j < numbers.size(); j++)
			{
				cur_sum += numbers[j];
				if (cur_sum > max_sum)
					max_sum = cur_sum;
			}
		}
		cout << max_sum << endl;
	}
	return 0;
}