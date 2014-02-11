#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line, tmp;
		vector<int> st;
		vector<int> nd;
		getline(fin, line, '|');
		stringstream ss(line);
		while (ss >> tmp)
			st.push_back(atoi(tmp.c_str()));
		getline(fin, line);
		stringstream ss2(line);
		while (ss2 >> tmp)
			nd.push_back(atoi(tmp.c_str()));
		for (size_t i = 0; i < st.size(); i++)
		{
			if (i != st.size() - 1)
				cout << st[i] * nd[i] << " ";
			else
				cout << st[i] * nd[i] << endl;
		}
	}
	fin.close();

	return 0;
}