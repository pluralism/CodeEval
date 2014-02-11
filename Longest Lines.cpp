#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


struct sort_desc {
	bool operator () (const string &s1, const string &s2)
	{
		return s1.size() > s2.size();
	}
};


int main(int argc, char* argv[])
{
	vector<string> lines;
	int N;
	bool has_N = false;
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty())
			continue;

		if (!has_N)
		{
			N = atoi(line.c_str());
			has_N = true;
		}
		else  lines.push_back(line);
	}
	sort(lines.begin(), lines.end(), sort_desc());
	for (int i = 0; i < N; i++)
		cout << lines[i] << endl;
	fin.close();
	return 0;
}