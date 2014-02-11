#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char *argv[])
{
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			if (j != 1)
				cout << setw(4) << i * j;
			else
				cout << i * j;
		}
		cout << endl;
	}
	return 0;
}