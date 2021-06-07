#include <iostream>
#include <cmath>
#include <map>

using namespace std;
int numDivisors(long long int number)
{
    int i = 2;
    int divisorCount = 1;
    // only counts to the square roots as that is the max divisor
    // higher divisor will be counted by the 2* at end from the fact divisors occur in pairs
    while(i <= sqrt(number))
    {   // a number greater than half of the value will never divide perfectly into that value
        // so no point checking
        if(i > number / 2)
        {
            //i = number;
        }
        if((number % i) == 0)
        {
            divisorCount += i;
            // we dont want to count the same divisor twice i.e if this value is the square root
            if(number / i != i)
            {
                divisorCount += (number / i);
            }
        }
        i++;
    }
    // the divisors occur in pairs i.e 2 * 28 = 56, so we count 2 but not 28
    // so we just multiply by 2 to get the total
    return divisorCount;
}
// sieve of eratosthenes implementation
// return a map of all primes up the limit
map<int,bool> sieve(int len)
{
    // limit is set at some value i thought the sum wouldn't pass
    int limit = 100000;
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
    // should be quicker, but prob doesn't work
}
// a very simple power function i made so i can be very accurate unlike cmath:pow()
int power(int base, int exp)
{
    int product = base;
    for(int i=0;i<exp - 1;i++)
    {
        product *= base;
    }
    return product;
}
int main() {
    int primesLen = 0;
    // map is used to store primes as i can easily check for a specific keys using .count method
    map<int,bool>primes = sieve(primesLen);
    int sum = 0;
    int n = 0;
    int greatestN = 0;
    int greatestA = 0;
    int greatestB = 0;
    //cout << d
    int b = 0;
    int a = 0;
    // flag for whether or not the value of a/b is negative
    bool aMinus = false;
    bool bMinus = false;
    int x=0;
    //int *primes = new int[1000000000];
    int powe = 0;
    while(abs(a) < 1000)
    {
        a++;
        b = 0;
        while(abs(b) <= 1000)
        {
            // if we just entered the loop, or checked both negative values of a and b, then we increment b
            if(!aMinus && !bMinus)
            {
                b++;
            }
            //cout << b << endl;
            n = 0;
            sum = 0;
            // loop runs and increments n until the equation no longer yields a prime
            while(primes.count(sum) > 0)
            {
                x++;
                powe = (int)(power(n,2));
                sum = powe + (a*n) + b;
                n++;
            } 
            // if this is the longest sequence then record these a b and n values as the max
            if(n > greatestN)
            {
                greatestN = n - 1;
                greatestA = a;
                greatestB = b;
            }
            // logic for setting a and b negative to get all the possible combinations
            if((!aMinus && !bMinus) || (aMinus && bMinus) )
            {
                a = -a;
                aMinus = !aMinus;
            }
            else if(bMinus == false || (bMinus))
            {
                b = -b;
                bMinus = !bMinus;
                //cout << " ";
                //cout << b << endl;
            }
            //cout << a << endl;
        }
    }
    // product of the a and values that lead to the longest sequence are outputted
    cout << greatestA * greatestB;
    
    return 0;
}