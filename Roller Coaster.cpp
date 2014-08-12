#include <iostream>
#include <fstream>
#include <string>
using namespace std;


string rollercoasterString(string &tmp)
{
	bool isuppercase = true;

	for (int i = 0; i < tmp.size(); i++)
	{
		if (isalpha(tmp[i]))
		{
			if (isuppercase)
				tmp[i] = toupper(tmp[i]);
			else
				tmp[i] = tolower(tmp[i]);

			isuppercase = !isuppercase;
		}
	}

	return tmp;
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string line;

			getline(fin, line);
			if (line.empty())
				continue;

			cout << rollercoasterString(line) << endl;
		}
		fin.close();
	}
	return 0;
}

