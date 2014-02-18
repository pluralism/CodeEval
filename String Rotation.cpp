#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


bool evalute(string s1, string s2)
{
	string tmp;
	int pos = s1.find(s2[0]);
	bool sContinue = true;
	if (pos == string::npos) {
		return false;
	}
	else {
		while (sContinue) {
			tmp = s1;
			rotate(s1.begin(), s1.begin() + pos, s1.end());
			if (s1 == s2)
				return true;
			else {
				s1 = tmp;
				pos = s1.find(s2[0], pos + 1);
				if (pos == string::npos)
					return false;
			}
		}
	}
}



int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string tmp = "";
		string line, f = "", s = "";
		getline(fin, line);
		if (line.empty())
			continue;

		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		ss >> f >> s;
		if (evalute(f, s))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	fin.close();
	return 0;
}