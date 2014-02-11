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
		string line, res;
		getline(fin, line);
		if (line.empty())
			continue;
		stringstream ss(line);
		int N;
		ss >> N;
		if (N == 0)
		{
			cout << "0" << endl;
			continue;
		}
		else {
			while (N)
			{
				res.push_back((N & 1) + '0');
				N >>= 1;
			}
			reverse(res.begin(), res.end());
			cout << res << endl;
		}
	}
	fin.close();
	return 0;
}