#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		vector<int> nums;
		bool found = false;
		int N;
		string line;
		getline(fin, line);
		if (line.empty())
			continue;
		stringstream ss(line);
		while (ss >> N)
			nums.push_back(N);

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] == nums[i])
				{
					int size = j - i;
					if (j + size < nums.size())
					{
						string s = "";
						string t = "";
						for (int k = i; k < i + size; k++)
						{
							s += to_string(nums[k]) + " ";
							t += to_string(nums[k + size]) + " ";
						}
						if (s == t) {
							s.erase(s.find_last_not_of(" \t") + 1);
							found = true;
							cout << s << endl;
						}
					}
				}
				if (found) break;
			}
			if (found) break;
		}
	}
	fin.close();
	return 0;
}