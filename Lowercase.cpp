#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void convert_lower(string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		convert_lower(line);
		cout << line << endl;
	}
	fin.close();
	return 0;
}