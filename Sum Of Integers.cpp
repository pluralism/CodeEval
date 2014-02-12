#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<int> numbers;
		string line;
		getline(fin, line);
		if (line.empty()) continue;
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int N;
		while (ss >> N)
			numbers.push_back(N);
		int max_ending_here = 0;
		int max_so_far = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			max_ending_here = max_ending_here + numbers[i];
			if (max_ending_here < 0) 
				max_ending_here = 0;
			else if (max_ending_here > max_so_far)
				max_so_far = max_ending_here;
		}
		cout << max_so_far << endl;
	}
	return 0;
}