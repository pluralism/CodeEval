#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;



int main(int argc, char* argv[])
{
	ifstream fin;
	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		int N, M;
		getline(fin, line);
		replace(line.begin(), line.end(), ',', ' ');
		istringstream ss(line);
		ss >> N >> M;
		while (N >= M)
			N -= M;

		cout << N << endl;
	}
	fin.close();
	return 0;
}