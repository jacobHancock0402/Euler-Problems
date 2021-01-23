#include <iostream>
#include "InfInt.h"
# include <cmath>

using namespace std;

int getNumDigits(InfInt value)
{
    //int digits = 0;
    //while(value != 0)
    //{
        //value = value/10;
        //digits++;
    //}
    //cout << digits 
    
    return value.numberOfDigits();
}
int main() {
    // the previous fibonacci values, starting at 1st and 2nd term
    InfInt f1 = 1;
    InfInt f2 = 1;
    InfInt value = 0;
    int digits = getNumDigits(value);
    int counter = 0;
    // index starts at 2, as we generate the third fibonacci in first iteration = 2+1
    int index = 2;
    while(digits < 1000)
    {
        counter++;
        value = f1+f2;
        f1 = f2;
        f2 = value ;
        //if(counter == 200 || digits > 950)
       // {
           // use the InfInt libraries method to get digits
            digits = getNumDigits(value);
        //}
        cout << digits << endl;
        index++;
    }
    //getNumDigits(30);
    // print index of 1000 digit term
    cout << index;
    return 0;

}