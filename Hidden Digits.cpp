#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		string numbers;
		for (int i = 0; i < line.size(); i++)
		{
			if (islower(line[i]) && (line[i] - 'a') >= 0 && (line[i] - 'a') <= 9)
				numbers += line[i] - 49;

			if (isdigit(line[i]))
				numbers += line[i];
		}
		if (numbers.empty())
			cout << "NONE" << endl;
		else
			cout << numbers << endl;
	}
	fin.close();

	return 0;
}