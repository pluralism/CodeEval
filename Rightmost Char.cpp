#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int get_pos(string &line, char c)
{
	for (int i = line.size() - 1; i >= 0; i--)
	if (line[i] == c)
		return i;

	return -1;
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		char c;

		getline(fin, line, ',');
		if (!line.empty())
		{
			fin >> c;
			fin.ignore();
			cout << get_pos(line, c) << endl;
		}
	}
	fin.close();
	return 0;
}