#include <iostream>
#include <map>
#include <cmath>

using namespace std;
bool * sieve(int len)
{
    // limit is set at some value i thought the sum wouldn't pass
    int limit = len;
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
    // int x = 0;
    // map<int, bool>actPrimes;
    // // list is searched and the indices that are set to true are added to the primes map, as they are primes
    // for(int e=0;e<limit;e++)
    // {
    //     if(primes[e])
    //     {
    //         actPrimes[e] = true;
    //        // cout << e << endl;
    //         x++;
    //     }
    // }

    //len = x;
    return primes;
    // should be quicker, but prob doesn't work
}
int power(int base, int exp)
{
    int product = base;
    if(exp == 0)
    {
        return 1;
    }
    for(int i=0;i<exp - 1;i++)
    {
        product *= base;
    }
    return product;
}
bool isPrime(long long int x) 
{
    for(long long int i=2;i<x;i++)
    {
        if(x%i == 0)
        {
            return false;
        }
        else if(i>(sqrt(x)))
        {
            break;
        }
    }
    return true;

}
int main()
{
	//bool *primes = sieve(100000000);
	int largest = 0;
	for(int i=1000000000;i>100000000;i--)
	{
		//cout << i << endl;
		map<int, bool> digits;
		bool doesntWork = false;
		for(int x=0;x<9;x++)
        {
            int digit = (i / power(10, x)) % 10;
            if(digits.count(digit) != 1 && digit != 0)
            {
                digits[digit] = true;
            }
            // if digit already seen or == 0, then break, not pandigital
            else
            {
                doesntWork = true;
                break;
            }
        }
        if(i == 987654321)
        {
        	cout << "wowo" << endl;
        }
        if(!doesntWork)
        {
        	//cout << i << endl;
        	if(isPrime(i))
        	{
        		largest=i;
        		break;
        	}
        }
	}
	cout << largest;
}