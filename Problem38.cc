
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
// simple power function, more accurate than pow
int power(int base, int exp)
{
    int product = base;
    if(exp == 0)
    {
        return 1;
    }
    for(int i=0;i<exp - 1;i++)
    {
        product *= base;
    }
    return product;
}
int main()
{
    // string *perms = new string[362880];
    // string str = "123456789";
    // int len = str.length();
    // auto [newPerms, length] = GetPermutations(str, perms, 0, len - 1, 0);
    //cout << "yo\n" << endl;
    bool found = false;
    int counter = 0;
    // a dynamically allocated array to hold all the 1-9 pandigital
    // doesn't actually serve any purpose, as i just keep track of the largest one outside of it
    string *candidates = new string[10000];
    int greatestValue = 0;
    // we check all ints from 1 to 9999, to check if 1-9 pandigital
    // the upper limit is set to this, as when i >= 10000, then sum of product digit cant equal 9 == cant be 1-9 pandigital
    for(int i=1;i<10000;i++)
    {
        //cout << i << endl;
        //int thouDivis = 10000/i;
        int totalLen = 0;
        int n = 0;
        // here we increase n until the len of the sum of products >= 9
        // the limit here is 500000 is arbitary. The loop will never actually hit this, as it breaks much sooner
        for(int j=1;j<500000;j++)
        {
           // cout << j << endl;
            n = j;
            int product = i*j;
            int len = trunc(log10(product)) + 1;
            totalLen += len;
            if(totalLen >= 9)
            {
                break;
            }
        }
        // cout << "hi" << endl;
        map<int, bool> digits;
        bool doesntWork = false;
        // if total len == 9, then still can be a 1-9 pandigital
        if(totalLen == 9)
        {
            // cout << "hifdfd" << endl;
            // we now recalculate the products, to check if any digit's repeat, and that only 1-9 are included
            // the reason i do this, instead of just doing it above when i have products, is that i eliminate alot of options above before doing this
            // and this bit is more intensive, so I thought it would be cheaper to have less numbers coming through here, even if i have to perform a few more calculations
            for(int u=1;u<=n;u++)
            {
                int product = i * u; 
                int len = trunc(log10(product)) + 1;
                for(int x=0;x<len;x++)
                {
                    int digit = (product / power(10, x)) % 10;
                    if(digits.count(digit) != 1 && digit != 0)
                    {
                        digits[digit] = true;
                    }
                    // if digit already seen or == 0, then break, not pandigital
                    else
                    {
                        doesntWork = true;
                        break;
                    }
                }
                if(doesntWork)
                {
                    break;
                }
            }
            // if it didn't eneter the else statement above, then it must be pandigital, as only 1-9 included
            // thus we collect it
            if(!doesntWork)
            {
                // i concatenate all the products to form a string, then convert back to an int to see if > greatest pandigital so far
                // I also store it in an array, but that isn't used
                string pandigital = "";
                for(int y=1;y<=n;y++)
                {
                    int product = y*i;
                    pandigital += to_string(product);
                     
                }
                int value = stoi(pandigital);
                if(value > greatestValue)
                {
                    greatestValue = value;
                }
                candidates[counter] = pandigital;
                counter++;
            }
                // else
                // {
                //     cout << "hi" << endl;
                //     string pandigital = "";
                //     for(int y=1;y<=n;y++)
                //     {
                //         int product = y*i;
                //         pandigital += to_string(product);
                         
                //             // Concatenate both strings
                         
                //             // Convert the concatenated string
                //             // to integer
                //     }
                //     int value = stoi(pandigital);
                //     if(value > greatestValue)
                //     {
                //         greatestValue = value;
                //     }
                //     candidates[counter] = pandigital;
                //     counter++;

                // }
            }
        }
        cout << greatestValue << endl;
    
    // for(int o=0;o<counter;o++)
    // {
    //     intCandidates[o] = stoi(candidates[0]);
    //     //cout << candidates[o] << endl;
    // }
    // bool sorted = false;
    // cout << counter << endl;
    // while(!sorted)
    // {
    //     int counters = 0;
    //     for(int y=0;y<counter - 1;)
    //     {
    //         if(intCandidates[y] < intCandidates[y+1])
    //         {
    //             int copy = intCandidates[y];
    //             intCandidates[y] = intCandidates[y+1];
    //             intCandidates[y+1] = copy;
    //             counters++;
    //         }
    //     }
    //     if(counters == 0)
    //     {
    //         break;
    //     }
    // }
    // cout << intCandidates[0];
    return 0;
}