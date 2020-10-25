#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int sumSquare = 0;
    for(int i=1;i<=100;i++)
    {
        sum +=i;
        sumSquare += (i * i);
    }
    cout << (sum * sum) - sumSquare;
    return 0;
}