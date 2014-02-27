#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


string to_String(int N)
{
	stringstream ss;
	ss << N;

	return ss.str();
}


string calculate(vector<int> numbers, int maxSum)
{
	string res = "";
	set<pair<int, int> > numbers_pairs;

	//O(N^2)
	for(int i = 0; i < numbers.size(); i++)
		for(int j = 0; j < numbers.size(); j++)
			if(i != j && (numbers[i] + numbers[j] == maxSum))
					numbers_pairs.insert(make_pair(min(numbers[i], numbers[j]), max(numbers[i], numbers[j])));

	if(numbers_pairs.size() == 0)
		return "NULL";
	else {
		for(set<pair<int, int> >::iterator it = numbers_pairs.begin(); it != numbers_pairs.end(); it++)
			res += to_String((*it).first) + "," + to_String((*it).second) + ";";
		res.erase(res.size() - 1);

		return res;
	}
}


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while(!fin.eof())
	{
		string line, maxSumString;
		getline(fin, line, ';');
		getline(fin, maxSumString);

		if(line.empty() || maxSumString.empty())
			continue;
		replace(line.begin(), line.end(), ',', ' ');
		int N, maxSum;
		vector<int> numbers;

		stringstream ss(line);
		while(ss >> N)
			numbers.push_back(N);
		maxSum = atoi(maxSumString.c_str());

		cout << calculate(numbers, maxSum) << endl;
	}

	fin.close();
	return 0;
}