#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while(!fin.eof())
	{
		string line;
		getline(fin, line);
		if(line.empty())
			continue;

		int step, N;
		vector<int> numbers;
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);

		ss >> N >> step;
		for(int i = 0; i < N; i++)
			numbers.push_back(i);

		int start = -1;
		while(!numbers.empty()) {
			start = (start + step) % numbers.size();
			cout << numbers[start % numbers.size()] << " ";
			numbers.erase(numbers.begin() + (start % numbers.size()));
			if(numbers.size() != 0)
				start = (start - 1 < 0 ? numbers.size() - 1 : (start - 1) % numbers.size());
		}
		cout << endl;
	}

	fin.close();
	return 0;
}