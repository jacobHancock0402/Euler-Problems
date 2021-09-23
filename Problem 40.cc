#include <iostream>

using namespace std;

int main()
{
	string str = "0";
	int total = 1;
	// create a str of the positive integers and 0
	for(int i=0;i<10000000;i++)
	{
		str += to_string(i);
	}
	// this then simply searches to string, and get's the product of the indices we want;
	for(int i=0;i<10000000;i++)
	{
		if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000)
		{
			//cout << str.at(i);
			total *= (str.at(i) - '0');
		
		}
	}
	// product = 210
	cout << total << endl;
	return 0;
}