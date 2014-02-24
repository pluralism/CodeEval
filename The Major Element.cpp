#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
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

		vector<int> nums;
		bool found = false;

		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int N;
		while(ss >> N)
			nums.push_back(N);

		int objective = nums.size() / 2;
		map<int, int> nums_map;
		int max = 0;
		int max_value = 0;


		for(int i = 0; i < nums.size(); i++) 
			nums_map[nums[i]]++;

		for(map<int, int>::iterator it = nums_map.begin(); it != nums_map.end(); it++) {
			if(it -> second > objective && it -> second > max) {
				max = it -> second;
				max_value = it -> first;
				found = true;
			}
		}

		if(found)
			cout << max_value << endl;
		else
			cout << "None" << endl;
	}
	fin.close();

	return 0;
}