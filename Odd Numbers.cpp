#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	for (int i = 1; i <= 99; i++)
	{
		if (i & 0x1)
			cout << i << endl;
	}
	return 0;
}