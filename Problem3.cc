#include <iostream>

using namespace std;
long long int factors[40000000];
int main() {
    long long int value = 600851475143;
    long long int j = 0;
    cout <<"good";
    /* value is cut by 3 places for optimation reason */
    for ( long long int i=(value / 1000);i>1;i--)
    {
        if(value % i == 0)
        {
            factors[j] = i;
            j++;
        }
    }
    bool found = false;
    long long int x = 0;
    int factor = 0;
    while(x < j)
    {
        int count = 0;
        for(int f=1;f<factors[x];f++)
        {
            if(factors[x] % f == 0 && f != 1)
            {
                break;
            }
            else
            {
                
                count++;
            }
            
        }
        if (count == factors[x] - 1)
        {
            found = true;
            factor = factors[x];
            break;
        }
        x++;
    }
    cout << factor;
    return 0;
}