#include <iostream>

#include "InfInt.h"

using namespace std;

int main() {
    InfInt value = 1;
    int sum = 0;
    // cant perform powers wit InfInt library so manually do with loop
    // start at power of one, and go up to power of 1000
    for(int i=1;i<1001;i++)
    {
        value = value * 2;
        cout << i << endl;
    }
    // sum all the digits of of 2 to power 1000 by using InfInt's methods
    for(int j=0;j<value.numberOfDigits();j++)
    {
        sum+=value.digitAt(j);
        cout << j << endl;
    }
    cout << sum;
}