#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while(!fin.eof())
	{
		string line;
		getline(fin, line);
		if(line.empty())
			continue;
		replace(line.begin(), line.end(), ',', ' ');
		int N, M, count = 0;
		stringstream ss(line);
		ss >> N >> M;
		int max = (int)sqrt((double) M);
		bool *arr = new bool[M + 1];
		for(int i = 0; i < M + 1; i++)
			arr[i] = false;


		for(int m = 2; m <= max; m++)
			if(!arr[m])
				for(int k = m * m; k <= M; k += m)
					arr[k] = true;

		for(int i = N; i <= M; i++)
			if(!arr[i])
				count++;

		cout << count << endl;
		delete[] arr;
	}

	return 0;
}