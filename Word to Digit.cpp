#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	map<string, string> numbers;
	numbers["zero"] = "0";
	numbers["one"] = "1";
	numbers["two"] = "2";
	numbers["three"] = "3";
	numbers["four"] = "4";
	numbers["five"] = "5";
	numbers["six"] = "6";
	numbers["seven"] = "7";
	numbers["eight"] = "8";
	numbers["nine"] = "9";
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		replace(line.begin(), line.end(), ';', ' ');
		stringstream ss(line);
		string tmp;
		string digits;
		while (ss >> tmp)
			digits += numbers[tmp];

		cout << digits << endl;

	}
	fin.close();
	return 0;
}