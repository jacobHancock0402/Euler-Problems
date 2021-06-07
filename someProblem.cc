#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
int valueInArray(int value, int array[], int len, string str, int pos)
{
    for(int i=0;i<len - 1;i++)
    {
        if(array[i] == value && array[i+1] == str[pos + 1] - '0' )
        {
            return i;
        }
    }
    return -1;
}
int main() {
    //setprecision(20);
    int maxRepeatLen = 0;
    int maxD = 0;
    for(double i=1.00;i<1000.00;i++)
    {
        double val = 1.00/i;
        string str = to_string(val);
        int len = str.length();
        //cout << str << endl;
        //int bad = stoi(str);
        string newStr = to_string(val * pow(10, 20));
        int decimals[len];
        int D = 0;
        int repeatLen = 0;
        for(int j=1;j<len;j++)
        {
            int check = valueInArray(newStr[j] - '0', decimals, len, newStr, j);
            if(i == 7.00)
            {
                //cout << check;
                //cout << newStr[j] - '0' << endl;
                //cout << newStr << endl;
                //cout << check;
                //cout << " ";
                //cout << j << endl;
            }
            if(check > -1)
            {
                repeatLen = j - check;
                D = i;
                break;
            }
            decimals[j] = newStr[j] - '0';

        }
        if(repeatLen > maxRepeatLen)
        {
            maxRepeatLen = repeatLen;
            maxD = D;
        }
        cout << setprecision(16);
        cout << fixed;
        cout << newStr;
        cout << "   ";
        cout << maxD << endl;
        //cout << len << endl;
        //cout << maxD << endl;
    }
    cout << maxD;
    cout << "  ";
    cout << maxRepeatLen;
    return 0;
}