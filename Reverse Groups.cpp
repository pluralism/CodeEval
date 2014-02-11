#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		int K;
		string line, number, tmp;
		vector<int> vecNum;
		getline(fin, line, ';');
		getline(fin, number);
		K = atoi(number.c_str());
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		while (ss >> tmp)
			vecNum.push_back(atoi(tmp.c_str()));
		int cur = 0;
		if (K < vecNum.size())
			reverse(vecNum.begin(), vecNum.begin() + K);
		cur += K;
		while (cur + K < vecNum.size()) {
			reverse(vecNum.begin() + cur, vecNum.begin() + cur + K);
			cur += K;
		}
		for (int i = 0; i < vecNum.size(); i++)
		if (i != vecNum.size() - 1)
			cout << vecNum[i] << ",";
		else
			cout << vecNum[i] << endl;
	}
	return 0;
}

