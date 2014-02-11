#include <iostream>
using namespace std;

bool endian()
{
	short int number = 0x1;
	char *c = (char*)&number;
	return (c[0] == 1);
}

int main(int argc, char* argv[])
{
	if (endian())
		cout << "LittleEndian";
	else
		cout << "BigEndian";
	return 0;
}