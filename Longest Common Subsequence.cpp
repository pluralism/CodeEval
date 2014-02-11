#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

string getLCSString(vector<vector<int> > C, string s1, string s2, int i, int j)
{
	if (i == 0 || j == 0)
		return "";
	else if (s1[i - 1] == s2[j - 1])
		return getLCSString(C, s1, s2, i - 1, j - 1) + s1[i - 1];
	else
	if (C[i][j - 1] > C[i - 1][j])
		return getLCSString(C, s1, s2, i, j - 1);
	else
		return getLCSString(C, s1, s2, i - 1, j);
}



void LCS(string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();
	vector<vector<int> > C(m + 1, vector<int>(n + 1));

	for (int i = 0; i < 1; i++)
	for (int j = 0; j <= n; j++)
		C[i][j] = 0;


	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				C[i][j] = C[i - 1][j - 1] + 1;
			else
				C[i][j] = max(C[i][j - 1], C[i - 1][j]);
		}
	}

	cout << getLCSString(C, s1, s2, m, n) << endl;
}


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string s1, str, s2;
		getline(fin, s1, ';');
		if (s1.empty())
			continue;

		getline(fin, s2);
		if (s2.empty())
			continue;

		LCS(s1, s2);
	}
	fin.close();
	return 0;
}