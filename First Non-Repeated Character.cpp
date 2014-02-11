#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
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
		map<char, int> chars;
		for (int i = 0; i < line.size(); i++)
		if (isalpha(line[i]))
			chars[line[i]]++;


		for (int i = 0; i < line.size(); i++)
		{
			if (chars.find(line[i])->second == 1)
			{
				cout << line[i] << endl;
				break;
			}
		}
	}
	fin.close();
	return 0;
}