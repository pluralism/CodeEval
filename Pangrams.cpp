#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <map>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		map<char, int> letters;
		bool found = false;
		string line;
		getline(fin, line);
		for (int i = 0; i < line.size(); i++) {
			if (isupper(line[i])) line[i] = tolower(line[i]);
			if (isalpha(line[i]))
				letters[line[i]]++;
		}

		for (int i = 'a'; i <= 'z'; i++) {
			if (letters[i] == 0) {
				cout << (char)i;
				found = true;
			}
		}
		if (!found) cout << "NULL";
		cout << endl;
	}
	fin.close();
	return 0;
}