#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int isGreaterThanAnyRight(int value, string str, int smallest)
{
    int thisVal = 0;
    int greatestVal = 0;
    int greatestIndex = 0;
    if(smallest == 0)
    {
        return -1;
    }
    else
    {
        for(int i=value;i<10;i++)
        {
            thisVal = str[i] - '0';
            if(thisVal < str[value] - '0' && thisVal > smallest)
            {
                if(thisVal > greatestVal)
                {
                    greatestVal = thisVal;
                    greatestIndex = i;
                }
            }
        }
    }
    if(greatestVal > 0)
    {
        return greatestIndex;
    }
    return -1;
    
}
int isGreaterThanAnyLeft(int value, string str){
    int val = 0;
    int thisVal = 0;
    for(int i=value;i>=0;i--)
    {
        val = str[value] - '0';
        thisVal = str[i] - '0';
        if(val > thisVal)
        {
            return 0;
            //return {i, val - thisVal};
        }
    }
    return 0;
    //return {-1,0};
}

int sortStuff() {
    //string str = "0123456789";
    //string tempString = "";
    //string permutations
    //int *checkLeft;
   // int checkRight;
   // char copy = 0;
   // int index = 0;
  //  while(counter < 1000000)
 //   {
       // for(int i=10;i>=0;i--)
      //  {
            //for(int j=0;j<10;j++)
            //{
          //  checkLeft = isGreaterThanAnyLeft(i, tempString);
           //// checkRight = isGreaterThanAnyRight(i, tempString, i - *(arrayReturn + 1) + 1)
           // if(*(arrayReturn + 0) > 0)
           // {
              //  if(checkRight == -1)
               // {
                   // index = *(checkLeft+0)
               // }
              ///  else
               // {
                   // index = checkRight
                //}
                //tempString = str;
                //copy = tempString[index] ;
                //tempString[index] = tempString[i];
               // tempString[i] = copy;
                //permutations[x] = tempString;
            //}
            //PushBack(tempString,i);
            //}
        //}
    //}
    return 0;
}
string reverseString(string str, int length)
{
    char copy;
    for(int i=0;i<length / 2;i++)
    {
        copy = str[i];
        str[i] = str[length - i - 1];
        str[length - 1 -i] = copy;
    }
    return str;
}
int main() {
    //cout << "i";
    //cout << reverseString("0123456789");
    string* permutations = new string[10000000];
    string str = "0123";
    int x=0;
    string tempString = "";
    char copy;
    while(x < 24)
    {
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            tempString = str;
            copy = tempString[j];
            tempString[j] = tempString[i];
            tempString[i] = copy;
            permutations[x] = tempString;
            permutations[x + 1] = reverseString(tempString,3);
            x+=2;
        }
    }
    }
    int* int_perms = new int[x+1];
    for(int y=0;y<x;y++)
    {
        int_perms[y] = stoi(permutations[y]);
        //cout << permutations[y] << endl;
    }
    bool sorted = false;
    while(sorted == false)
    {
        int counter = 0;
        int copy = 0;
        for(int w=0;w<x-1;w++)
        {
            if(int_perms[w] > int_perms[w+1])
            {
                copy = int_perms[w];
                int_perms[w] = int_perms[w+1];
                int_perms[w+1] = copy;
            }
            else
            {
                counter++;
            }
            
        }
        if(counter == x - 1)
        {
            sorted = true;
        }
    }
    for(int e=0;e<=x;e++)
    {
        cout << int_perms[e] << endl;
    }
    delete[] permutations;
    delete[] int_perms;
    return 0;
}