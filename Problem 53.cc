#include <iostream> 
#include "InfInt.h"
#include <map>

using namespace std;

InfInt rational(int limit, map<int, InfInt> &factorials) 
{
	InfInt sum = 1;
	if(factorials.count(limit) == 0)
	{
		for(InfInt i=1;i<=limit;i++)
		{
			sum *= i;
		}
		factorials[limit] = sum;
	}
	sum = factorials[limit];
	//cout << "hi" << endl;
	return sum;
}
int main()
{
	// this is a brute force method that simply find how many there are from using the binomial formula
	int count = 0;
	map<int, InfInt> factorials;
	// i represents n here, so we go from the 3(i set it at this as i know none less will be > 10000000), to the upper limit of 100
	for(int i=3;i<=100;i++)
	{
		//cout << i << endl;
		// j represents r, so we go from 2(0 always gives us 1, and 1 always gives us n, neither of which are > 1000000) to i/2, as the binomials will be symmetric
		for(int j=2;j<(i/2) + 1;j++)
		{
			//cout << j << endl;
			//cout << rational(i) + "yyee" << endl;
			//calculating the binomial
			InfInt value = (rational(i, factorials)) / (rational(j, factorials) * rational(i-j, factorials));
			//cout << value << endl;

			//cout << "yo" << endl;
			//cout << "hi" + value << endl;
			if(value > 1000000)
			{
				//cout << "gobaby" + i << endl;
				//cout << "biatch" << endl;
				// as mentioned before binomials are symmetric, i.e 4C3 = 4C1, 7C2 == 7C5, and thus if NCK is > 1000000, where k < i/2, then NC(N-K) will also be >1000000, and thus we can increment twice
				// but if K == 2, then there will be no symmetry as it is at the center, so we only increment once
				if(j != i/2 || i%2 == 0)
				{
					count++;
				}
				count++;
			}
		}
	}
	// number is output
	cout << count << endl;
	// i've seen someone calculate the pascal triangle and store the data, which seems like a cool, and perhaps quicker solution;
}