#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;
	map<int, string> numerals;
	numerals[1] = "I";
	numerals[4] = "IV";
	numerals[5] = "V";
	numerals[9] = "IX";
	numerals[10] = "X";
	numerals[40] = "XL";
	numerals[50] = "L";
	numerals[90] = "XC";
	numerals[100] = "C";
	numerals[400] = "CD";
	numerals[500] = "D";
	numerals[900] = "CM";
	numerals[1000] = "M";

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		string numeral;
		getline(fin, line);
		int N = atoi(line.c_str());
		bool flag = false;
		while (N >= 0)
		{
			int tmp;
			for (map<int, string>::reverse_iterator it = numerals.rbegin(); it != numerals.rend(); it++)
			{
				if ((*it).first <= N)
				{
					tmp = (*it).first;
					numeral += (*it).second;
					flag = true;
				}
				if (flag)
					break;
			}
			N -= tmp;
			flag = false;
		}
		cout << numeral << endl;
	}
	fin.close();

	return 0;
}