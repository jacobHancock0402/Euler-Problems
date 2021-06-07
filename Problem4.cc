#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;
bool isPalindromic(int number, string str = NULL)
{
    if(str == NULL)
    {
        string str = to_string(number);
    }
    int length = str.length();
    char st[length];
    sprintf(st, "%d", number);
    for(int x=0;x<length / 2;x++)
    {
        if(str[x] != str[length - x - 1])
        {
            return false;
        }
    }
    return true;
}
int main() {
    long int largest = 0;
    for(int i=999;i>99;i--)
    {
        for(int j=999;j>99;j--)
        {
            int number = j * i;
            /*cout << "lol";
            sprintf(str, "%d", number);
            int y = (sizeof(str) / sizeof(*str));
            for(int x=0;x<(sizeof(str) / sizeof(*str));x++)
            {
                char copy = str[x];
                str[x] = str[y];
                str[y] = copy;
            }
            */
           if(number > largest)
           {
            bool palindromic = isPalindromic(number);
                if(palindromic == true)
                {
                    largest = number;
                }
           }
        }
    }
    cout << largest;
    return 0;
}
