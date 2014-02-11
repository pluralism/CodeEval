#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		stringstream ss(line);
		string tmp, longest = "";
		while (ss >> tmp)
		if (tmp.size() > longest.size())
			longest = tmp;

		cout << longest << endl;
	}
	fin.close();
	return 0;
}