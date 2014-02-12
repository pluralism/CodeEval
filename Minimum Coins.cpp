#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

//DP solution
int main(int argc, char *argv[])
{
	ifstream fin;
	vector<int> values;
	values.push_back(5);
	values.push_back(3);
	values.push_back(1);
	int N = values.size();
	fin.open(argv[1]);
	while (!fin.eof())
	{
		int S;
		fin >> S;
		vector<int> Min(S + 1, INT_MAX);
		Min[0] = 0;
		for (int i = 1; i <= S; i++) {
			for (int j = 0; j <= N - 1; j++) {
				if (values[j] <= i && Min[i - values[j]] + 1 < Min[i])
					Min[i] = Min[i - values[j]] + 1;
			}
		}
		cout << Min[S] << endl;
	}
	return 0;
}