#include <iostream>
#include <fstream>
#include <sstream>
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
		bool flag = false;
		for (int i = 0; i < line.size(); i++)
		{
			int N = line[i] - '0';
			int t = 0;
			for (int j = 0; j < line.size(); j++)
			{
				if ((line[j] - '0') == i)
					t++;
			}
			if (t != N)
				flag = true;
			if (flag)
				break;
		}
		if (flag)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}
	fin.close();

	return 0;
}