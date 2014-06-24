#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;



int main(int argc, char *argv[])
{
	ifstream fin;
	
	fin.open(argv[1]);
	while(!fin.eof())
	{
		int possibilites = 0;
		string line;
		getline(fin, line);
		
		if(line.empty())
			continue;
		
		vector<int> vec(line.length() + 1);
		vec[0] = 1;
		possibilites++;
		
		
		for(int i = 1; i < line.length(); i++)
		{				
			string tmp = line.substr(i - 1, 2);
			int double_number = atoi(tmp.c_str());
			if(double_number <= 26)
				possibilites++;
		}
		
		cout << possibilites << endl;
	}
	fin.close();
	return 0;
}

