#include <iostream>
#include <map>
#include "InfInt.h"

using namespace std;
InfInt power(int base, int exp)
{
    // very simple power function to power infints
    InfInt value = base;
    for(int i=0;i<exp - 1;i++)
    {
        value *= base;
    }
    return value;
}
int main() {
    // map storing all the calculated values
    map<InfInt, bool>allVals;
    int vals = 0;
    // computes the power of a to b for all their combinations as they vary from 2-100
    for(int a=2;a<=100;a++)
    {
        for(int b=2;b<=100;b++)
        {
            InfInt value = power(a,b);
            // if value is distinct then increment sequence length
            if(allVals.count(value) < 1)
            {
                vals++;
            }
            // create a key for this element
            // if key is already created it won't matter as the bool does nothing
            allVals[value] = true;
        }
    }
    // sequence length is outputted
    cout << vals;
    return 0;
}