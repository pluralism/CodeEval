#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;


bool valid(string s)
{
	stack<char> vals;
	if (s.length() == 1) 
		return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			vals.push(s[i]);

		if (s[i] == ')')
		{
			if (vals.size() == 0 || vals.top() != '(')
				return false;
			else
				vals.pop();
		}

		if (s[i] == '}')
		{
			if (vals.size() == 0 || vals.top() != '{')
				return false;
			else
				vals.pop();
		}

		if (s[i] == ']')
		{
			if (vals.size() == 0 || vals.top() != '[')
				return false;
			else
				vals.pop();
		}
	}

	return true;
}



int main(int argc, char *argv[])
{
	ifstream fin;
	
	fin.open(argv[1]);
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		if (line.empty())
			continue;
		if (valid(line))
			cout << "True";
		else
			cout << "False";
		cout << endl;
	}
	fin.close();
	return 0;
}