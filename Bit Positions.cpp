#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		int bit1, bit2, number;
		string line;

		getline(fin, line);
		int t = line.find(',');

		if (t != string::npos)
		{
			number = atoi(line.substr(0, t).c_str());
			int t2 = line.find(',', t + 1);

			if (t2 != string::npos)
			{
				bit1 = atoi(line.substr(t + 1, t2 - t + 1).c_str()) - 1;
				bit2 = atoi(line.substr(t2 + 1, line.length() - t2 + 1 + 1).c_str()) - 1;

				if (((number >> bit1) & 1) == ((number >> bit2) & 1))
					cout << "true" << endl;
				else
					cout << "false" << endl;
			}
		}
	}
	fin.close();
	return 0;
}

