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
		string sentence;
		string line;
		string key;
		getline(fin, line, '|');
		getline(fin, key);
		stringstream ss(key);
		string tmp;
		while (ss >> tmp)
			sentence += line[atoi(tmp.c_str()) - 1];

		cout << sentence << endl;
	}
	fin.close();
	return 0;
}