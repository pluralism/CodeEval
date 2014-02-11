#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<string> words;
		string word = "", line = "";
		int last_space = 0;
		getline(fin, line);
		if (!line.empty())
		{
			stringstream ss(line);
			string s;
			while (ss >> s)
				words.push_back(s);

			for (int i = words.size() - 1; i >= 0; i--)
			{
				cout << words[i];
				if (i > 0)
					cout << " ";
			}
			cout << endl;
		}
	}
	fin.close();

	return 0;
}