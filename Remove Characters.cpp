#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line, res, chars_to_remove;
		getline(fin, line, ',');
		if (line.empty())
			continue;
		getline(fin, chars_to_remove);
		for (int i = 0; i < line.size(); i++)
		{
			if ((chars_to_remove.find(line[i]) == string::npos) || isspace(line[i]))
				res += line[i];
		}
		cout << res << endl;
	}
	fin.close();
	return 0;
}