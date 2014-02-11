#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


template<typename Iterator>
void heapsort(Iterator begin, Iterator end)
{
	make_heap(begin, end);
	while (begin != end)
		pop_heap(begin, end--);
}

int main(int argc, char* argv[])
{
	ifstream fin;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty())
			continue;

		vector<double> numbers;
		stringstream ss(line);
		double s;
		while (ss >> s)
			numbers.push_back(s);

		heapsort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size(); i++)
		{
			if (i != numbers.size() - 1)
				cout << fixed << setprecision(3) << numbers[i] << " ";
			else
				cout << fixed << setprecision(3) << numbers[i];
		}
		cout << endl;
	}
	fin.close();
	return 0;
}