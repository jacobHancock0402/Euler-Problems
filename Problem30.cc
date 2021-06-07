#include <iostream>
#include "InfInt.h"
#include <cmath>

using namespace std;
int power(int base, int exp)
{
    // very simple power function to power infints
    int value = base;
    for(int i=0;i<exp - 1;i++)
    {
        value *= base;
    }
    if(exp == 0)
    {
        return 1;
    }
    return value;
}
int main() {
    int len = 1;
    int x = 0;
    int sum = 0;
    int values[100];
    // checks all numbers up to a million to see if they pass the conditions
    // i chose a million because 100000 was too small
    for(int i=2;i<10000000;i++)
    {
        sum = 0;
        // these are pretty stupid if conditions to find length
        // i didn't want to bother with writing a loop to find the length of the int, so opted for this beautiful creation
        if(i > 10)
        {
            len = 2;
        }
        if(i> 100)
        {
            len = 3;
        }
        if(i > 1000)
        {
            len = 4;
        }
        if(i > 10000)
        {
            len = 5;
        }
        if(i > 100000)
        {
            len = 6;
        }
        // loop that sums each digit powered to 5
        for(int j=0;j<len;j++)
        {
            // the quotient and remainder arithmetic is used to get the digits
            sum += power(((i / (power(10,j))) % 10), 5);
        }
        // if the sum is equal to the number, then it passes the conditons so add to the list
        if(sum == i)
        {
            values[x] = i;
            x++;
        }
    }
    InfInt product = 0;
    // all the values in the array are summed
    for(int y=0;y<x;y++)
    {
        product += values[y];
        cout << values[y] << endl;
    }
    // sum is outputted
    cout << product;
    return 0;
}