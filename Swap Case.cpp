#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		for (size_t i = 0; i < line.size(); i++)
		{
			if (isupper(line[i]) && isalpha(line[i]))
				line[i] = tolower(line[i]);
			else if (islower(line[i]) && isalpha(line[i]))
				line[i] = toupper(line[i]);
		}
		cout << line << endl;
	}
	fin.close();
	return 0;
}