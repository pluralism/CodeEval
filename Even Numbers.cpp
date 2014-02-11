#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
		if (atoi(line.c_str()) % 2 == 0)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	fin.close();
	return 0;
}