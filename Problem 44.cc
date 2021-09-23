#include <iostream>
#include <map>

using namespace std;
int main()
{
	// map that stores all the pentagons numbers as keys, used to check if a number is pentagonal
	map<int, bool> pentagons;
	// I didnt use the formula, instead i noticed that the difference between numbers increases by 3 each time, with it starting at 4
	int additive = 4;
	pentagons[1] = true;
	int num = 1;
	// the limit is arbitrary. I increased by power of 10 until i found a solution
	int limit = 10000;
	// this stores all of the keys as an array
	int* keys = new int[limit];
	keys[0] = 1;
	// here we get all the pentagonal numbers up to the limit
	for(int i=1;i<limit;i++)
	{
		pentagons[num + additive] = true;
		keys[i] = num + additive;
		num = keys[i];
		additive += 3;
	} 
	// we loop through these numbers
	// an inner loop will find the difference and sum of all pentagonal number less than the one selected by outer loop
	for(int i=0;i<limit;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			int difference = keys[i] - keys[j];
			int sum = keys[i] + keys[j];
			// we check if the sum is pentagonal first
			if(pentagons.count(sum) > 0)
			{
				// then if difference is also pentagonal
				if(pentagons.count(difference) > 0)
				{
					// if so, then this number is output
					// this must be the least difference as the difference increases as you go along , and went from the least term, so must be minimsed there
					// and i also started the second loop at the term i-1, thus minimising the difference between the two terms there(although i noticed that the answer would have been the same even if i had started from 0)
					cout << difference << endl;
					exit(0);
				}
			}
		}
	}
}