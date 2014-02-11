#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/**
* NOTE: Possible the worst solution on CodeEval
*/
int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		bool found = false;
		string line, repetition;
		getline(fin, line);
		for (int i = 0; i < line.size(); i++)
		{
			string tmp = "";
			repetition += line[i];
			while (tmp.size() < line.size())
				tmp += repetition;

			if (tmp == line)
				found = true;
			if (found)
				break;
		}
		cout << repetition.size() << endl;
	}
	return 0;
}