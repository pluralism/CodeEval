#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>s
using namespace std;


string last_word(string line)
{
	stringstream ss(line);
	string s;
	vector<string> words;
	while (ss >> s)
		words.push_back(s);

	if (words.size() > 0)
		return words[words.size() - 2];

	return "";
}

int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;

		getline(fin, line);
		cout << last_word(line) << endl;
	}
	fin.close();
	return 0;
}

