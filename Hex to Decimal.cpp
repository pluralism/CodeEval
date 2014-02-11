#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;


int calc_num(string num)
{
	int total = 0;

	for (size_t i = 0; i < num.size(); i++)
		total += ((num[i] > '9' ? (num[i] - 'a' + 10) : num[i] - '0') * pow(16, num.size() - 1 - i));

	return total;
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		cout << calc_num(line) << endl;
	}
	fin.close();
	return 0;
}