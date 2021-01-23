#include <iostream>
#include "InfInt.h"
#include <string>

using namespace std;
string CutZeroes(string str, int len )
{
    char character = str[len - 1];
    int count = 0;
    while(character == '0')
    {
        count++ ;
        character = str[len - 1-count];
    }
    str.erase(len-1-count,len);
    return str;

}
int main()
{
    //setprecision(200);
    double one = 1;
    string str = "";
    int best_length = 0;
    int best_i = 0;
    double value = 0;
    int length = 0;
    for(double i=2;i<1000;i++)
    {
        value = one / i;
        str = to_string(value);
        str = CutZeroes(str, str.length());
        length = str.length();
        if(length > best_length)
        {
            best_i = i;
            best_length = length;
        }
    }
    cout << best_i << endl;
    cout << best_length;
    return 0;
}