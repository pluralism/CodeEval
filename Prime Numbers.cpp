#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		int start = 2;
		int N;
		fin >> N;
		if (N > 2) {
			vector<int> values(N + 1, 0);
			int limit = (int)sqrt((double)N);
			while (start <= limit) {
				if (values[start] == 0) {
					for (int i = 2 * start; i <= N; i += start)
						values[i] = 1;
					start++;
				}
				else {
					start++;
					continue;
				}
			}
			string tmp = "";
			for (int i = 2; i <= N; i++)
			if (values[i] == 0)
				tmp += "," + to_string(i);
			if (!tmp.empty()) tmp.erase(tmp.begin() + 0);
			cout << tmp << endl;
		}
		else cout << endl;
	}
	fin.close();
	return 0;
}