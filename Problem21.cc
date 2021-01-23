#include <iostream>
#include <cmath>

using namespace std;
bool searchArray(int array[], int value, int size)
{
    //cout << "size";
    //cout << size << endl;
    for(int i=0;i<size - 1;i++)
    {
        if(value == array[i])
        {
            //cout << "bigdub";
            //cout << value;
            //cout << "ok";
            //cout << array[i];
            return true;
        }
    }
    return false;
}
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
            i = number;
        }
        if((number % i) == 0)
        {
            divisorCount += i;
            divisorCount += (number / i);
        }
        i++;
    }
    // the divisors occur in pairs i.e 2 * 28 = 56, so we count 2 but not 28
    // so we just multiply by 2 to get the total
    return divisorCount;
}

int main() {
    int sum = 0;
    int amicableNumbers[20] = {};
    int x = 0;
    for(int i=1;i<10000;i++)
    {
        //cout << i << endl;
        long long int sumDivisors = numDivisors(i);
        if(numDivisors(sumDivisors) == i && sumDivisors != i )
        {
            //if(searchArray(amicableNumbers,sumDivisors,x + 1) == false && searchArray(amicableNumbers,i,x + 1) == false)
            //{
                sum+=i;
                //sum+=sumDivisors;
                amicableNumbers[x] = i;
                x++;
            //}
        }
    }
    for(int j=0;j<20;j++)
    {
        cout << amicableNumbers[j] << endl;
    }
    cout << sum;
}