#include <iostream>
#include <math.h>

using namespace std;
int numDivisors(long long int number)
{
    int i = 1;
    int divisorCount = 0;
    // only counts to the square roots as that is the max divisor
    // higher divisor will be counted by the 2* at end from the fact divisors occur in pairs
    while(i <= sqrt(number))
    {   // a number greater than half of the value will never divide perfectly into that value
        // so no point checking
        if(i > number / 2)
        {
            i = number;
        }
        if((number % i) == 0)
        {
            divisorCount += 1;
        }
        i++;
    }
    // the divisors occur in pairs i.e 2 * 28 = 56, so we count 2 but not 28
    // so we just multiply by 2 to get the total
    return 2 * divisorCount;
}
int main() {
    int prevNum = 0;
    int natNum = 0;
    int natNumCount = 0;
    int number = 0;
    //cout << numDivisors(2016);
    for(long long int i=1;i<10000000000000;i++)
    {
        // calculating the sum of natural numbers by adding i to the previous triangle number
        natNum = i + prevNum;
        prevNum = natNum;
        int sum = numDivisors(natNum);
        if(sum > 500)
        {
            number = natNum;
            //cout << "die";
            //cout << sum;
            //cout << i;
            break;
        }
    }
    cout << number;
}