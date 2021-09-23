#include <iostream>
#include "InfInt.h"
using namespace std;
InfInt power(int base, int exp)
{
    // very simple power function to power ints
    InfInt value = base;
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
int main()
{
	// straight up brute forc method
	// used the infint library to allow the big numbers to be seen
	// then just did as the question asked, summing through for loops
	InfInt sum = 0;
	for(int i=1;i<1000;i++)
	{
		//cout << i << endl;
		sum+=power(i,i);
		//cout << sum << endl;
	}
	for(int i=0;i<10;i++)
	{
		//int length = sum.numberOfDigits() - 1;
		//cout << length << endl;
		//cout << sum.digitAt(length - i);
	}
	cout << sum << endl;
}