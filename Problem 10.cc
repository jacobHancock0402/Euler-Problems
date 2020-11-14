#include <iostream>
#include <math.h>

using namespace std;
bool isPrime(long long int x) {
    for(long long int i=2;i<x;i++)
    {
        if(x%i == 0)
        {
            return false;
        }
        else if(i>(sqrt(x)))
        {
            break;
        }
    }
    return true;

}
int main() {
    long long int total = 0;
    for(int i=2;i<2000000;i++)
    {
        if(isPrime(i) == true)
        {
            total +=i;
        }
    }
    cout << total;
    return 0;
}