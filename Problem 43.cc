#include <iostream>
#include <map>

using namespace std;
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
int main(){
for(int i=1000000000;i>100000000;i--)
	{
		//cout << i << endl;
		map<int, bool> digits;
		int *actDigits = new int[10];
		bool doesntWork = false;
		for(int x=0;x<9;x++)
        {
            int digit = (i / power(10, x)) % 10;
            actDigits[x] = digit;
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
	    // if(!doesntWork)
	    // {
	    // 	string str = to_string(i);
	    // 	for(int j=2;j<9;j++)
	    // 	{
	    // 		str.substr(j, j+2)
	    // 	}
	    // }
	}
}