#include <iostream>
#include <cmath>
#include <map>

using namespace std;
class Rotation {
	public :
	int *rotations;
	int length;
};
// something wrong with how i get the rotatations, pretty much doesn't work, like doesn't give any
// it's also quite slow, almost impossible to run at high numbers like a million, considering slows as gets larrger
// might be partially because of the cout's , but rpob would be too slow anyway
// also would prob want to add the original rotation, as i think i need that
// the error should be fixed no
// so it works, but doubtful it would work for a milion because of performance
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
map<int, bool> sieve(int len)
{
    // limit is set at some value i thought the sum wouldn't pass
    int limit = 1000000;
    bool *primes = new bool[limit];
    int removed = 0;
    // instantiating a list with each index set to true
    // the bool acts as a way to see whether is has been "removed" or not, without actually removing
    for(int i=2;i<limit;i++)
    {
        primes[i] = true;
    }
    // the actual sieve
    for(int y=2;y<limit;y++)
    {
        // check is this number has been removed
        if(primes[y])
        {
            // list runs until the the number we are at squared > limit
            // i use the inaccurate pow here because we don't need to be extremely precise
            if(pow(y, 2) > limit)
            {
                break;
            }
            // for this number, it will remove all it's multiples from the list
            for(int j=2;j<limit;j++)
            {
                if(j % y == 0 && j != y)
                {
                    primes[j] = false;
                    removed++;
                }
            }
        }
    }
    int x = 0;
    map<int, bool>actPrimes;
    // list is searched and the indices that are set to true are added to the primes map, as they are primes
    for(int e=0;e<limit;e++)
    {
        if(primes[e])
        {
            actPrimes[e] = true;
           // cout << e << endl;
            x++;
        }
    }

    len = x;
    return actPrimes;
}
map<int, bool>primes = sieve(0);
Rotation GetRotations(int number)
{
	
	int len = trunc(log10(number)) + 1;
	int *digits = new int[len];
	int *rotations = new int[len];
	int ogNumber = number;
	bool flag = true;
	// if len == 1, then it will just treat as a circular prime, as must be because it has only one rotation, which is prime
	if(len > 1)
	{
		// getting digits by divide by 10 the power and then taking the remainder when dividing by 10, which always gives the last digit
		// we also check if the digit is divisble by 2 or 4
		// if it is, then we know atleast one rotation will not be prime, so not circular
		// this only improves performance slightly
		for(int y=len - 1;y>=0;y--)
		{
			digits[y] = (((int)(number / (power(10,y)))) % 10);
			if(digits[y] % 2 == 0 || digits[y] % 5 == 0)
			{
				flag = false;
				rotations[0] = 0;
				break;
			}
		}
		int tenToPowerLen = (power(10,len - 1));
		// this loop creates len - 2 rotations, by pushing the first digit from [0] to [1], so all rotations are checked
		if(flag)
		{
			for(int i=0;i<len - 1;i++)
			{
				int firstDig = number / tenToPowerLen;
				int thirdToLenDigits = 0;
				// this loop works by getting the second digit, multiplying it by 10 to make it first digit
				// and then adding on the rest of the digits * 10, + first digit, as it is now the last digit
				if(len >= 3)
				{
					thirdToLenDigits = (number % power(10, len - 2)) * 10;
				}
				int secondDig = (((int)(number / (power(10, len - 2)))) % 10) * tenToPowerLen;
				rotations[i] = secondDig + thirdToLenDigits + firstDig;
				number = rotations[i];
				// if rotation isn't prime, then we can exit and say return that it isn't a circ prime
				if(!primes[rotations[i]])
				{
					rotations[0] = 0;
					break;
				}
			}
		}
	}
	Rotation rot;
	rot.rotations = rotations;
	rot.length = len;
	return rot;

}
int main()
{
	int *circularPrimes = new int[1000000];
	int circularPrimesCounter = 0;
	for(int i=1;i<1000000;i++)
	{
		// if i is prime, we check if circular prime
		if(primes[i])
		{			
			// we get the rotations, and if [0] == 0, then it isn't a circular prime, else it is
			Rotation rotations = GetRotations(i);
			int counter = 0;
			if(rotations.rotations[0] != 0)
			{
				circularPrimes[circularPrimesCounter] = i;
				circularPrimesCounter++;
			}
		}
	}
	// print the number of circular primes under one million
	cout << circularPrimesCounter;
	return 0;
}
