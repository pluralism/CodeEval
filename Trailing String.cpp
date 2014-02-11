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
		string s1, s2;
		getline(fin, s1, ',');
		if (s1.empty()) continue;
		getline(fin, s2);
		if (s2.empty()) continue;
		if (s1.find(s2) != string::npos)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	fin.close();
	return 0;
}