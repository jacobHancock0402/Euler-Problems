// Online C++ compiler to run C++ program online 

#include <iostream> 

#include <cmath> 

#include <string> 

 

using namespace std; 

int total = 0; 

    int values1[10] = {4,3,3,5,4,4,3,5,5,4}; 

    int values2[8] = {6,6,5,5,5,7,6,6};
    int values3[10] = {3,6,6,8,8,7,7,9,8,8};

    int hundred = 7; 

    int thousand = 8; 

    int an = 3; 

int count2Digits(int i, int total) { 

    int nd = i % 10; 

    int st = (i / 10)%10;
    if(nd != 0 || st != 0) 
    {
        if(nd != 0)
        {
            total += values1[nd];
        }
        total += values2[st - 2]; 
    }
 

    return total; 

     

} 

int main() { 

    //long long int number  = pow(2,1000); 

    //string num = to_string(number); 

    //int total = 0; 

    //for(int i=0;i<num.length();i++) 

    //{ 

        //int var = num[i] - '0'; 

        //total += (var); 

    //} 

    //cout << total; 

    //return 0; 

    for(int i=1;i<=1000;i++) 
    { 

        if(i<10) 

        { 

            total += values1[i]; 

        } 
        else if(i < 20)
        {
            int nd = i % 10;
            total += values3[nd];
        }

        else if(i<100) 
        { 
            total = count2Digits(i, total); 

        } 

        else if(i<1000) 

        { 
            if(((i / 10) %  10) == 0)
            {
                if((i % 10) != 0)
                {
                    total += values1[(i % 10)];
                }
            }
            else if(((i/10) % 10) < 2)
            {
                total += values3[i % 10];
            }
            else
            {
                total = count2Digits(i, total);
            } 

            int st = (i /100)%10; 

            total += values1[st]; 

            total += hundred; 
            if((((i/10) % 10) != 0) || (i % 10) != 0)
            {
                total += an; 
            }

             

        } 

        else 

        { 

            total += thousand; 

            total += values1[1]; 

        } 
        cout << total << endl;

    } 

    cout << total; 
    // works
     

} 