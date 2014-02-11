#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line, s;
		getline(fin, line);
		vector<string> list;
		int N;

		stringstream ss(line);
		while (ss >> s)
		{
			bool isN = false;
			if (isdigit(s[0]))
				isN = true;
			if (isN)
				N = atoi(s.c_str());
			else list.push_back(s);
		}
		if (N > list.size())
			continue;
		else
			cout << list[list.size() - N] << endl;
	}
	fin.close();
	return 0;
}