#include <iostream>
#include "InfInt.h"

using namespace std;

int main() {
    InfInt sum = 1;
    // calculate the factorial of 100
    for(int i=1;i<=100;i++)
    {
        sum = sum * i;
        cout << i << endl;
    }
    int total = 0;
    // sum all of factorials digits using InfInt methods
    for(int j=0;j<sum.numberOfDigits();j++)
    {
        total += sum.digitAt(j);
        cout << j << endl;
    }
    cout << total;
}