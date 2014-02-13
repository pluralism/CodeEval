#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		bool should_print = true;
		stack<int> numbers;
		string line;
		getline(fin, line);
		stringstream ss(line);
		int N;
		while (ss >> N)
			numbers.push(N);

		while (numbers.size() > 0)
		{
			if (should_print)
			{
				should_print = false;
				cout << numbers.top() << " ";
			}
			else should_print = true;
			numbers.pop();
		}
		cout << endl;
	}
	fin.close();
	return 0;
}