#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int calculate_pascal(int row, int col)
{
	if (col == 0 || col == row)
		return 1;
	else
		return calculate_pascal(row - 1, col - 1) + calculate_pascal(row - 1, col);
}


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty())
			continue;
		int N;
		string s = "";
		stringstream ss(line);
		ss >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				s += to_string(calculate_pascal(i, j)) + ((j == i && i == (N - 1)) ? "" : " ");
		cout << s << endl;
	}

	fin.close();
	return 0;
}