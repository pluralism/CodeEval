#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isPrime(int number)
{
	for (int i = 2; i < number; i++)
	if (number % i == 0 && i != number)
		return false;

	return true;
}


string convert_to_string(int number)
{
	stringstream ss;
	ss << number;

	return ss.str();
}

bool isPalindrome(int number)
{
	string s = convert_to_string(number);

	for (size_t i = 0; i < s.length() / 2; i++)
	if (s[i] != s[s.length() - i - 1])
		return false;

	return true;
}

int main(int argc, char *argv[])
{
	for (size_t i = 1000; i >= 0; i--)
	if (isPalindrome(i) && isPrime(i))
	{
		cout << i;
		break;
	}

	return 0;
}