#include <iostream>
#include <fstream>
using namespace std;


void calculate(int A, int B, int N)
{
	for (int i = 1; i <= N; i++)
	{
		if ((i % A == 0) && (i % B == 0))
			cout << "FB";
		else if (i % A == 0)
			cout << "F";
		else if (i % B == 0)
			cout << "B";
		else
			cout << i;

		cout << (i == N ? "" : " ");

		if (i == N)
			cout << endl;
	}
}


int main(int argc, char *argv[])
{
	int A, B, N;
	ifstream fin;
	fin.open(argv[1]);

	while (!fin.eof())
	{
		fin >> A >> B >> N;
		calculate(A, B, N);
	}
	fin.close();

	return 0;
}