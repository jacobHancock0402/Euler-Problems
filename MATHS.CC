#include <iostream>

using namespace std;

int main()
{
	for(int i=0;i<1000;i++)
	{
		int sum = 0;
		string str = to_string(i);
		for(int x=0;x<str.length();x++)
		{
			sum += str[x] - '0';
		}
		if(sum == 3 )
		{
			cout << i << endl;
		}
	}
}