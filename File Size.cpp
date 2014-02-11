#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	FILE *file;
	long size;

	file = fopen(argv[1], "rb");
	if (file != NULL)
	{
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		fclose(file);

		cout << size << endl;
	}
	return 0;
}