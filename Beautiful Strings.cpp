#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		int start = 26, total = 0;
		string line;
		getline(fin, line);
		vector<int> letters(27);

		for (int i = 0; i < line.size(); i++)
		if (isalpha(line[i]))
			letters[(char)tolower(line[i]) - 'a']++;

		sort(letters.begin(), letters.end());
		for (int i = letters.size() - 1; i >= 0; i--)
			total += (start-- * letters[i]);
		cout << total << endl;
	}
	return 0;
}