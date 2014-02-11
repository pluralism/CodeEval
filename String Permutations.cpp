#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		vector<string> perms;
		getline(fin, line);
		sort(line.begin(), line.end());
		do {
			perms.push_back(line);
		} while (next_permutation(line.begin(), line.end()));
		for (int i = 0; i < perms.size(); i++)
			cout << perms[i] << (i != perms.size() - 1 ? "," : "");
		cout << endl;
	}


	return 0;
}