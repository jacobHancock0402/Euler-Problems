
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

// string Swap(int dig1, int dig2, string str)
// {
//     char copy = str[dig1];
//     //cout << dig1;
//     //cout << " ";
//     //cout << dig2;
//     str[dig1] = str[dig2];
//     str[dig2] = copy;
//     //cout << "theString" + str << endl;
//     return str;
// }
// tuple<string*, int> GetPermutations(string str, string *permutations, int counter, int len, int index)
// {
//     //permutations[counter] = str;
//     //counter++;
//     //cout << "yhhh";
//     if(index == len)
//     {
//         //return permutations
//         //cout << "str " + str + " " + to_string(counter) << endl;
//         permutations[counter] = str;
//         counter++;

//         return {permutations, counter};
//     }
//     else
//     {
//         for(int i=index;i<=len;i++)
//         {
//             //cout << i << endl;
//             str = Swap(i, index, str);
//             //permutations[counter] = str;
//             //counter++;
//             //cout << "yo" + permutations[counter] + " ";
//             auto [newPerms, newCounter] = GetPermutations(str, permutations, counter, len, index+1 );
//             counter = newCounter;
//             permutations = newPerms;
//             str = Swap(i, index, str);
//         }
//     }
//     return {permutations, counter};
// }
int main()
{
    // string *perms = new string[362880];
    // string str = "123456789";
    // int len = str.length();
    // auto [newPerms, length] = GetPermutations(str, perms, 0, len - 1, 0);
    cout << "yo\n" << endl;
    bool found = false;
    int counter = 0;
    string *candidates = new string[1000];
    cout << "yo" << endl;
    while(!found)
    {
        for(int i=2;i<1000;i++)
        {
            int thouDivis = 1000/i;
            int totalLen = 0;
            int n = 0;
            for(int j=1;j<thouDivis;j++)
            {
                n = j;
                int product = i*j;
                int len = trunc(log10(product)) + 1;
                totalLen += len;
                if(totalLen >= 9)
                {
                    break;
                }
            }
            map<int, bool> digits;
            bool doesntWork = false;
            if(totalLen == 9)
            {
                for(int u=1;u<=n;u++)
                {
                    int product = i * u; 
                    int len = trunc(log10(product)) + 1;
                    for(int x=1;x<len;x++)
                    {
                        int digit = (product / x) % 10;
                        if(!digits.count(digit))
                        {
                            digits[digit] = true;
                        }
                        else
                        {
                            doesntWork;
                            break;
                        }
                       
                    }
                    if(doesntWork)
                    {
                        break;
                    }
                    else
                    {
                        string pandigital = "";
                        for(int y=1;y<=n;y++)
                        {
                            int product = y*i;
                            pandigital += to_string(product);
                             
                                // Concatenate both strings
                             
                                // Convert the concatenated string
                                // to integer
                        }
                        candidates[counter] = pandigital;
                        counter++;
                    }
                }
            }
        }
    }
    cout << "hi" << endl;

    for(int o=0;o<counter;o++)
    {
        cout << candidates[o] << endl;
    }
    return 0;
}