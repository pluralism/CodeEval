#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[])
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
		string i;
		stringstream ss(line);
		while (ss >> i)
		{
			bool found = false;
			for (int k = 0; k < i.size(); k++)
			{
				if (!isdigit(i[k]) && i[k] != '.' && i[k] != '-')
					found = true;
				if (found)
					break;
			}
			if (!found)
				numbers.push_back(atoi(i.c_str()));
		}
		int max = *max_element(numbers.begin(), numbers.end());
		vector<int> other(max + 1);

		for (int i = 0; i < numbers.size(); i++)
			other[numbers[i]]++;
		int last = -1;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] != last)
			{
				last = numbers[i];
				cout << other[numbers[i]] << " " << numbers[i] << " ";
			}
		}
		cout << endl;
	}
	fin.close();
	return 0;
}