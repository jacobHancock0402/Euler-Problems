
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int power(int base, int exp)
{
    // very simple power function to power ints
    int value = base;
    if(exp == 0)
    {
    	return 1;
    }
    for(int i=0;i<exp - 1;i++)
    {
        value *= base;
    }
    return value;
}
bool isPalindromic(int number, string str = "")
{
	// here we just have two alternate paths
	// one where we are given a string, so we just use it's indices
	// or one where we find the digits of the number
    if(str == "")
    {
    	int len = trunc(log10(number)) + 1;
		int *digits = new int[len];
        for(int y=len - 1;y>=0;y--)
		{
			digits[y] = (((int)(number / (power(10,y)))) % 10);
		}
		for(int x=0;x<len / 2;x++)
    	{
    		// we check through each digit and see if the one on the opposite to it on the int is the same
    		// if not we return false
    		// else if none are inequal, then palindromic
	        if(digits[x] != digits[len - x - 1])
	        {
	            return false;
	        }
    	}
	}
    else
    {
    	int length = str.length();
    	for(int x=0;x<length / 2;x++)
    	{
	        if(str[x] != str[length - x - 1])
	        {
	            return false;
	        }
    	}
    }
    return true;
}
string DecToBinary(int number)
{
	int counter = 0;
	char *chars = new char[100];
	int ogNumber = number;
	// this is a method i found on a dec to binary calcultor
	// works by dividing the number by 2
	// this can either have a remainder of 0 or 1
	// so we just set  the char at this index to the remainder
	// this then repeat with the quotient of the division, and this continues until the quotient = 0
	// i don't really understand fully why this works, but it is useful
	while(number != 0)
	{
		int remainder = number % 2;
		number = number / 2;
		// convert the int to char
		chars[counter] = remainder + '0';
		counter++;
	}
	// convert the char* to a string
	string str = chars;
	// resize array so it only includes the chars we have placed, no dead space
	str.resize(counter);
	// you might notice that this string will actually be in reverse
	// but this doesn't matter, as we are only using to check if palindromic, which will have same result on both sides if it is
	return str;
}
int main()
{
	int sum = 0;
	// check all numbers under million
	for(int i=1;i<1000000;i++)
	{
		// if i is palindromic
		if(isPalindromic(i))
		{
			// then get it's binary and check if that's palindromic
			string Binary = DecToBinary(i);
			if(isPalindromic(0, Binary))
			{
				// if so then we add i to the sum
				sum += i;
			}
		}
	}
	cout << sum;
	return 0;
}