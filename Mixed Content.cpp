#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<int> numbers;
		vector<string> words;
		string line;
		getline(fin, line);
		replace(line.begin(), line.end(), ',', ' ');
		string tmp;
		stringstream ss(line);
		while (ss >> tmp)
		{
			bool found_number = false;
			for (int i = 0; i < tmp.size(); i++)
			{
				if (isdigit(tmp[i]))
					found_number = true;

				if (found_number)
					break;
			}
			if (found_number)
				numbers.push_back(atoi(tmp.c_str()));
			else
				words.push_back(tmp);
		}

		for (int i = 0; i < words.size(); i++)
		{
			if (i != words.size() - 1)
				cout << words[i] << ",";
			else
				cout << words[i];
		}

		if (numbers.size() > 0 && words.size() > 0)
			cout << "|";

		for (int i = 0; i < numbers.size(); i++)
		{
			if (i != numbers.size() - 1)
				cout << numbers[i] << ",";
			else
				cout << numbers[i];
		}
		cout << endl;
	}
	fin.close();

	return 0;
}