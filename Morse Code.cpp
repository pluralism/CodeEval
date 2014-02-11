#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	map<string, char> morse;
	morse[".-"] = 'A';
	morse["-..."] = 'B';
	morse["-.-."] = 'C';
	morse["-.."] = 'D';
	morse["."] = 'E';
	morse["..-."] = 'F';
	morse["--."] = 'G';
	morse["...."] = 'H';
	morse[".."] = 'I';
	morse[".---"] = 'J';
	morse["-.-"] = 'K';
	morse[".-.."] = 'L';
	morse["--"] = 'M';
	morse["-."] = 'N';
	morse["---"] = 'O';
	morse[".--."] = 'P';
	morse["--.-"] = 'Q';
	morse[".-."] = 'R';
	morse["..."] = 'S';
	morse["-"] = 'T';
	morse["..-"] = 'U';
	morse["...-"] = 'V';
	morse[".--"] = 'W';
	morse["-..-"] = 'X';
	morse["-.--"] = 'Y';
	morse["--.."] = 'Z';
	morse["-----"] = '0';
	morse[".----"] = '1';
	morse["..---"] = '2';
	morse["...--"] = '3';
	morse["....-"] = '4';
	morse["....."] = '5';
	morse["-...."] = '6';
	morse["--..."] = '7';
	morse["---.."] = '8';
	morse["----."] = '9';
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty())
			continue;

		for (int i = 0; i < line.size() - 1; i++)
		if (line[i] == 0x20 && line[i + 1] == 0x20)
			line[i + 1] = '|';

		stringstream ss(line);
		string tmp;
		while (ss >> tmp)
		{
			if (tmp[0] == '|')
				cout << ' ' << morse[tmp.substr(1, tmp.size())];
			else
				cout << morse[tmp];
		}
		cout << endl;
	}
	fin.close();
	return 0;
}