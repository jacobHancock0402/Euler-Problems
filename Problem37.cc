#include <iostream>
#include <cmath>
#include <map>

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
map<int, bool> sieve(int limit)
{
    // limit is set at some value i thought the sum wouldn't pass
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

    //len = x;
    return actPrimes;
}
int main()
{
	int limit = 1000000;
    int counter = 0;
	map<int, bool>primes = sieve(limit);
	int sum = 0;
    // we don't consider any integers < 10 trunctable, so don't check them
    // i set a limit of 1000000 because i looked up the largest left and right truncatable prime, and it was < million
    // i know this isn't the best way of doing things, but otherwise i'd have to keep increasing the value until i had eleven primes
    // or i could have run the loop until i had 11 primes, but this run the risks of infinite while loops if my code is bad
    // obviously there's probably a method that uses neither, by no brute forcing it, but this worked well for me
	for(int i=10;i<limit;i++)
	{
        if(primes[i])
        {
    		int len = trunc(log10(i)) + 1;
    		bool prime = true;
            // we check if right trunctable by cutting off all but 1st digit, then all but first 2 digits, and so forth
            // on each iteration we check if the new number is prime
            // if all iteration are prime, then we check if left truncatable
    		for(int x=1;x<len;x++)
    		{
    			if(!primes[i / (power(10, x))])
    			{
    				prime = false;
    				break;
    			}
    		}
            // if right truncatable
    		if(prime)
    		{
                // similar method to above, but for left truncatable, so know we are cutting of all but the last digit 1st
    			for(int y=1;y<len;y++)
    			{
                    if(i == 23)
                    {
                    }
    				if(!primes[i % (power(10, y))])
    				{
    					prime = false;
    					break;
    				}
    			}
    		}
            // if left and right truncatable, we sum it to the total
    		if(prime)
    		{
    			sum+=i;
                counter++;
    		}
        }
	}
	cout << sum;
	return 0;
}