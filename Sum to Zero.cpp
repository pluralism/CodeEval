#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int nWays(vector<int> n)
{
	int count = 0;

	for (int i = 0; i < n.size(); i++)
	for (int j = i + 1; j < n.size(); j++)
	for (int k = j + 1; k < n.size(); k++)
	for (int w = k + 1; w < n.size(); w++)
	if (n[i] + n[j] + n[k] + n[w] == 0)
		count++;

	return count;
}



int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty())
			continue;

		vector<int> numbers;
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int N;

		while (ss >> N)
			numbers.push_back(N);
		cout << nWays(numbers) << endl;
	}
}