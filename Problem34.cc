#include <iostream>
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
// this return an array of all single digit factorial
int* GetFactorials()
{
	int* factorials = new int[10];
	int counter = 2;
	// one iteration for each factorial
	for(int j=2;j<10;j++)
	{
		// we set the factorial at the index to one so we are actually multiplying a correct value, i.e not just dead space
		factorials[counter] = 1;
		// multiply 1 by 2, 3, 4, up to j, the factorial
		for(int i=2;i<=j;i++)
		{
			factorials[counter] *= i;
		}
		counter++;
	}
	return factorials;
}
int main()
{
	int *Factorials = new int[10];
	// as we only need the factorials of 0-9, we can just fill an array, where the index indicates the factorial, and the value obviously indicates its value
 	Factorials = GetFactorials();
 	// we don't calculate these in GetFactorials, so set them here
 	Factorials[0] = 1;
	Factorials[1] = 1;
	// the limit is set quite abitralily, and it so happened that i got it right
	// i know bad method but what can you do
	int limit = 1000000;
	int total = 0;
	// we don't consider 1 or 2, so just check from 3
	for(int i=3;i<limit;i++)
	{
		int len = trunc(log10(i)) + 1;
		int sum = 0;
		// sum the factorial of the numbers's digits
        for(int y=len - 1;y>=0;y--)
		{
			int digit = (((int)(i / (power(10,y)))) % 10);
			sum += Factorials[digit];
		}
		// if sum == number, then is factorion, so add it to the total
		if(sum == i)
		{
			total += i;
		}
	}
	cout << total << endl;
	return 0;
}