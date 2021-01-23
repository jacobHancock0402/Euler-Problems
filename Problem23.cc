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
// spare function
bool searchArray(int value, int array[], int length)
{
    int meanValue = array[length/2];
    if(value < meanValue)
    {
        for(int i=0;i<length;i++)
        {
            if(value == array[i])
            {
                return true;
            }
            else if(value < array[i])
            {
                return false;
            }
        }
    }
    else
    {
        for(int i=length - 1;i>=0;i--)
        {
            if(value == array[i])
            {
                return true;
            }
            else if(value > array[i])
            {
                return false;
            }
        }
    }
    return false;
}
int main() {
    int abundantNumbers[10000];
    int x = 0;
    // finds all abundant numbers up to 28123
    for(int i=1;i<=28123;i++)
    {
        if(numDivisors(i) > i)
        {
            abundantNumbers[x] = i;
            x++;
        }
    }
    unsigned long long int sum = 0;
    bool sorted = false;
    // bubble sort the abundant numbers for optimisation
    while(sorted == false)
    {
        int count = 0;
        for(int e=0;e<x;e++)
        {
            if(abundantNumbers[e] > abundantNumbers[e+1])
            {
                int copy = abundantNumbers[e];
                abundantNumbers[e] = abundantNumbers[e+1];
                abundantNumbers[e+1] = copy;
            }
            else
            {
                count++;
            }
            if(count == x)
            {
                sorted = true;
            }
        }
    }
    cout << "done";
    bool sums = false;
    map <int,bool> abSums;
    //for(int p=0;p<=x;p++)
    //{
        //cout << abundantNumbers[p] << endl;
    //}
    // fill a map with all the sums of abundant numbers, 
    //allows us to use .count method to check if number is present
    for(int u=0;u<=x;u++)
    {
        for(int f=0;f<=x;f++)
        {
            if(abundantNumbers[u] != 0 && abundantNumbers[f] != 0)
            {
                abSums[abundantNumbers[u]+abundantNumbers[f]] = true;
            }
        }
    }
    // checks all numbers up 28123 to see if they can be formed from the sum of two abundant numbers
    // if not, the number is added to total
    for(int j=1;j<=28123;j++)
    {
        sums = false;
        if(abSums.count(j))
        {
            sums = true;
        }
        else
        {
            sums = false;
            cout << j << endl;
        }
        
        //for(int y = 0;y<=x;y++)
        //{
            //if(j < abundantNumbers[y])
            //{
                //break;
            //}
            //else if (j >= abundantNumbers[y] && ((j - abundantNumbers[y] >= abundantNumbers[0]) && (j-abundantNumbers[y] <= abundantNumbers[x])))
            //{
                //if((j-abundantNumbers[y]) == abundantNumbers[y])
                //{
                    //sums = true;
                    //break;
                //}
                //else if(searchArray(j-abundantNumbers[y],abundantNumbers,x + 1) == true && abundantNumbers[y] != 0)
               //{
                    //sums = true;
                    //break;
                //}
            //}
        //}
        //cout << j << endl;
        if(sums == false)
        {
            sum+=j;    
        }
        //cout << sum << endl;
        //cout << "gethebag";
        //cout << j << endl;
    }
    // ok well this is straight broke
    // swear have very similar method to solution but doesn't work and has just stayed at same value for iterations
    // if i come back on, just gonna straight up copy the solutions
    cout << sum;
    return 0;
}