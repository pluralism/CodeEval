#include <iostream>
using std::cout;
using std::endl;


bool isPrime(int number)
{
	for (int i = 2; i < number; i++)
	if (number % i == 0 && i != number)
		return false;

	return true;
}


int main(int argc, char *argv[])
{
	int total = 0;
	int primes = 0;

	for (int i = 2; primes < 1000; i++)
	if (isPrime(i))
	{
		primes++;
		total += i;
	}
	cout << total << endl;

	return 0;
}