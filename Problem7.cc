#include <iostream>

using namespace std;
bool isPrime(long long int x) {
    for(long long int i=2;i<x;i++)
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;

}
int main() {
    int primeCount = 0;
    int prime = 0;
    for (long long int x=2;x < 1000000000000;x++)
    {
        if(isPrime(x) == true)
        {
            primeCount++;
        }
        if(primeCount == 10001)
        {
            prime = x;
            break;
        }
    }
    cout << prime;
    
}