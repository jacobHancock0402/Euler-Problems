#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;
// int fast_atoi(string str)
// {
//     int val = 0;
//     while(*str)
//     {
//         val = val*10 + (*str++ - '0');
//     }
//     return val;
// }
string Swap(int dig1, int dig2, string str)
{
    char copy = str[dig1];
    //cout << dig1;
    //cout << " ";
    //cout << dig2;
    str[dig1] = str[dig2];
    str[dig2] = copy;
    //cout << "theString" + str << endl;
    return str;
}
void SwapIndices(long long int *a, long long int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
tuple<string*, int> GetPermutations(string str, string *permutations, int counter, int len, int index)
{
    //permutations[counter] = str;
    //counter++;
    if(index == len)
    {
        //return permutations
        //cout << "str " + str + " " + to_string(counter) << endl;
        permutations[counter] = str;
        counter++;

        return {permutations, counter};
    }
    else
    {
        for(int i=index;i<=len;i++)
        {
            //cout << i << endl;
            str = Swap(i, index, str);
            //permutations[counter] = str;
            //counter++;
            //cout << "yo" + permutations[counter] + " ";
            auto [newPerms, newCounter] = GetPermutations(str, permutations, counter, len, index+1 );
            counter = newCounter;
            permutations = newPerms;
            str = Swap(i, index, str);
        }
    }
    return {permutations, counter};
}
int partition(long long int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low;j<= high - 1;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            SwapIndices(&arr[i], &arr[j]);
        }
    }
    SwapIndices(&arr[i+1], &arr[high]);
    return (i+1);
}
void quickSort(long long int *arr, int low, int high)
{
    //cout << "***REMOVED***" << endl;
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi+1, high);
        //cout << "lol";
    }

}
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
    string *perms = new string[3628800];
    long long int *intPerms = new long long int[3628800];
    string str = "0123456789";
    int len = str.length();
    auto [newPerms, length] = GetPermutations(str, perms, 0, len - 1, 0);
    cout << length;
    cout << " ";
    int counter = 0;
    //cout << stoi("012");
    for(int i=0;i<length;i++)
    {
        intPerms[i] = stoll(newPerms[i]);
    }
    //bool sorted = false;
    // while(!sorted)
    // {
    //     bool change = false;
    //     long long int str1 = stoll(newPerms[0]);
    //     long long int str2 = 0;
    //     for(int i=0;i<length - 1;i++)
    //     {
    //         str2 = stoll(newPerms[i + 1]);
    //         if(str1>str2)
    //         {
    //             string copy = newPerms[i];
    //             newPerms[i] = newPerms[i+1];
    //             newPerms[i+1] = copy;
    //             change = true;
    //         }
    //         str1 = str2;
    //     }
    //     sorted = !change;
    // }
    //quickSort(intPerms, 0, length - 1);
    cout << intPerms[1000000];
    // 2785960341
    //cout << newPerms[length - 1];
    // for(int i=0;i<length;i++)
    // {
    //     cout << newPerms[i] << endl;
    // }
    //cout << "i";
    // //cout << reverseString("0123456789");
    // string* permutations = new string[10000000];
    // string str = "0123";
    // int x=0;
    // string tempString = "";
    // char copy;
    // while(x < 24)
    // {
    // for(int i=0;i<4;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     {
    //         tempString = str;
    //         copy = tempString[j];
    //         tempString[j] = tempString[i];
    //         tempString[i] = copy;
    //         permutations[x] = tempString;
    //         permutations[x + 1] = reverseString(tempString,3);
    //         x+=2;
    //     }
    // }
    // }
    // int* int_perms = new int[x+1];
    // for(int y=0;y<x;y++)
    // {
    //     int_perms[y] = stoi(permutations[y]);
    //     //cout << permutations[y] << endl;
    // }
    // bool sorted = false;
    // while(sorted == false)
    // {
    //     int counter = 0;
    //     int copy = 0;
    //     for(int w=0;w<x-1;w++)
    //     {
    //         if(int_perms[w] > int_perms[w+1])
    //         {
    //             copy = int_perms[w];
    //             int_perms[w] = int_perms[w+1];
    //             int_perms[w+1] = copy;
    //         }
    //         else
    //         {
    //             counter++;
    //         }
            
    //     }
    //     if(counter == x - 1)
    //     {
    //         sorted = true;
    //     }
    // }
    // for(int e=0;e<=x;e++)
    // {
    //     cout << int_perms[e] << endl;
    // }
    // delete[] permutations;
    // delete[] int_perms;
    // return 0;
}