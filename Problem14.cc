#include <iostream>

using namespace std;

int main () {
    long long int value = 0;
    int greatest_Length = 0;
    int length = 0;
    long long int greatest_Value = 0;
    //int costs[10000000];
    cout << "hi" << endl;
    // runs loop for every number under a millio
    for(int i=1;i<1000000;i++)
    {
        value = i;
        length = 0;
        // performs collatz sequence until number is 1
        while(value != 1)
        {
            //here i tried to implement a caching system, but the program errored because of lack of memory
            // the way it would have worked is storing the length of each i sequence
            // then the future calculations could just add that value once they reached there instead of recalculating
            
            //if(costs[value])
           // {
                //length += costs[value];
                //break;
            //}
            // if even, divide by two
            if(value % 2 == 0)
            {
                value = value / 2;
            }
            // else must be odd so mutliply by 3 and add 1
            else
            {
                value = (3 * value) + 1;
            }
            length++;
            //cout << length << endl;
        }
        // if this is the longest chain so far, set it so
        if(length > greatest_Length)
        {
            greatest_Length = length;
            greatest_Value = i;
        }
        cout << i ;
        cout << "a"; 
        cout << length << endl;
    }
    cout << greatest_Value;
    return 0;
}