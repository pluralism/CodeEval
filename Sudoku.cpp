#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;


bool valid(vector<int> vec)
{
	vector<int> positions(*max_element(vec.begin(), vec.end()) + 1);
	for(int i = 0; i < vec.size(); i++)
	{
		positions[vec[i]]++;
		if(positions[vec[i]] > 1)
			return false;
	}		

	return true;
}


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while(!fin.eof())
	{
		bool valid_board = true;
		int N;
		int size;
		vector<int> numbers;
		string line;
		getline(fin, line, ';');
		size = atoi(line.c_str()); //Tabuleiro NxN
		line = "";
		getline(fin, line);
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		while(ss >> N)
			numbers.push_back(N);


		for(int i = 0; i < numbers.size() - size; i += size)
		{
			vector<int> tmp(numbers.begin() + i, numbers.begin() + i + size);
			sort(tmp.begin(), tmp.end());
			if(!valid(tmp))
			{
				valid_board = false;
				break;
			}
		}
		
		if(!valid_board)
			cout << "False" << endl;
		else
			cout << "True" << endl;
	}

	fin.close();
	return 0;
}