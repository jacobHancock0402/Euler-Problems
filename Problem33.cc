#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <math.h>
// this program doesn't fully work even though it 100% should
// something wrong with the compiler, where freezes on division of 4 and 2
using namespace std;
// a class so I can return 2 data types from a function
class DivisorReturn {
	public : 
	int *divisors;
	int length;
};
// this is a modified version of the NumDivisors function i've used in many of the problems
DivisorReturn GetDivisors(int number)
{
    int i = 1;
    int divisorCount = 0;
    int counter = 0;
   	int *divisors = new int[50];
    // only counts to the square roots as that is the max divisor
    // higher divisor will be counted by the 2* at end from the fact divisors occur in pairs
    // this isn't really needed but I added it to check if would fix the errors
    if(number != 0 )
    {
	    while(i <= sqrt(number))
	    {   // a number greater than half of the value will never divide perfectly into that value

	        // so no point checking
	        cout << i << endl;
	        if(i > number / 2)
	        {
	            i = number;
	        }
	        // cout << "***REMOVED***";
	        // cout << i;
	        // cout << " ";
	        // cout << number;
	        // cout << " ";
	        // cout << number/i  << endl;
	        // this bit is literally broke, i get number / i completely fine here, but in the branch, it freezes
	        if((number % i) == 0)
	        {
	        	//cout << "twat";
	            divisors[counter] = i;
	            divisors[counter+1] = number/i;
	            // cout << number;
	            // cout << " ";
	            // cout << number/i << endl;
	            counter+=2;
	        }
	        i++;
	    }
	}
    // the divisors occur in pairs i.e 2 * 28 = 56, so we count 2 but not 28
    // so we just multiply by 2 to get the total
    // i use an object to store an array and it's length
    // this allows me to get the endpoint of the array without using a vector or list
  	DivisorReturn divisorRet;
  	divisorRet.divisors = divisors;
  	divisorRet.length = counter;
    return divisorRet;
}
int* CanSimplify(int arr[])
{
	//cout << "gogetme" << endl;
	// collect all divisors of the numerator and denominator
	DivisorReturn iRet = GetDivisors(arr[0]);
	DivisorReturn jRet = GetDivisors(arr[1]);
	//cout << "lo" ;
	int iLen = iRet.length;
	int jLen = jRet.length;
	int *iDivisors = iRet.divisors;
	int *jDivisors = jRet.divisors;
	cout << iDivisors[0];
	//cout << "wedidit" << endl;
	int counter = 0;
	bool sorted = false;
	int *array = new int[2];
	cout << "fat";
	// this sorts the divisors by value, asc order, so I can go from the back and grab the highest common factor
	// thinking about, maybe i should have just done desc order, then wouldn't need length maybe?
	// i also don't use the denominators divisors, so wasn't any need in sorting, but performance is fine anyway
	while(sorted == false)
	{
		for(int i=0;i<iLen - 1;i++)
		{
			if(iDivisors[i] > iDivisors[i+1])
			{
				int copy = iDivisors[i];
				iDivisors[i] = iDivisors[i+1];
				iDivisors[i+1] = copy;
				counter++;
			}
		}
		for(int j=0;j<jLen - 1;j++)
		{
			if(jDivisors[j] > jDivisors[j+1])
			{
				int copy = jDivisors[j];
				jDivisors[j] = jDivisors[j+1];
				jDivisors[j+1] = copy;
				counter++;
			}
		}
		if(counter == 0)
		{
			sorted = true;
		}
	}
	// this goes through the divisors of the numerator, and check if the denom is also divisible by them
	// if so, this is largest common factor(because of the sorting above) so num and denom are divided by this to give simplest version
	// we don't have to check the factors for denom, as these will be either larger than num, thus invalid, or they'll be here anyway
	for(int x=iLen - 1;x>=0;x++)
	{
		if((arr[0] % iDivisors[x]) == 0)
		{
			// s
			array[0] = arr[0] / iDivisors[x];
			array[1] = arr[1] / iDivisors[x];
			return array;
		}
	}
	// if no common factor, can't be simplified
	array[0] = 0;
	return array;

}
int main()
{
	int counter = 0;
	// we are collecting 4 pairs of numerators and denominators
	float nonValid[2][4];
	for(int i=1;i<100;i++)
	{
		// i = num, denom = j
		for(int j=1;j<100;j++)
		{
			// we can only form fractions < 1, thus num < denom
			if(j>i)
			{
				// grabbing digits
				int idig1 = i % 10;
				int idig2 = (i/10) % 10;
				int jdig1 = j % 10;
				int jdig2 = (j/10) % 10;
				int *newDigi = new int[4];
				int *newDigj = new int[4];
				int count = 0;
				// we check if there any matches in denom and numerator
				// if so, then we the one's that dont to 2 seperate array, with same index, like a pair
		
				if(idig1 == jdig1 && jdig1 != 0)
				{
					newDigi[count] = idig2;
					newDigj[count] = jdig2;	
					count++;
				}
				if(idig1 == jdig2 && jdig2 != 0)
				{
					newDigi[count] = idig2;
					newDigj[count] = jdig1;	
					count++;			
				}
				if(idig2 == jdig1 && idig2 != 0)
				{
					newDigi[count] = idig1;
					newDigj[count] = jdig2;	
					count++;
				}
				if(idig2 == jdig2 && jdig2 != 0)
				{
					newDigi[count] = idig1;
					newDigj[count] = jdig1;	
					count++;			
				}
				//cout << "***REMOVED***g" << endl;
				// cout << idig1 << endl;
				// cout << idig2 << endl;
				// cout << jdig1 << endl;
				// cout << jdig2 << endl;
				if(count > 0)
				{
					for(int w=0;w<count;w++)
					{
						//cout << "***REMOVED***yyy" << endl;
						// here i just grab the non cancelled digits in num and denom
						int thisDigi = newDigi[w];
						int thisDigj = newDigj[w];
						//cout << newDigi[w] << endl;
						// float casts to get the exact real value
						float digiDiv = ((float)thisDigi)/((float)thisDigj);
						float ijDiv = ((float)i)/((float)j);
						// cout << "i";
						// cout << i ;
						// cout << " ";
						// cout << thisDigi;
						// cout << " j";
						// cout << j;
						// cout << " ";
						// cout << thisDigj;
						// cout << " ";
						// cout << ijDiv;
						// cout << " ";
						// cout << digiDiv << endl;
						// if the values of the fractions are equal, then the cancelling did simplify it, so check if trivial
						if(digiDiv == ijDiv)
						{
							//cout << "yeah" << endl;
							int *arr = new int[2];
							arr[0] = thisDigi;
							arr[1] = thisDigj;
							//cout << "boys" << endl;
							// ok, so i don't actually understand what a non-trivial example is
							// when writing this, i thought it was when it wasn't completely simplified
							// but i don't think that's the case, and more so that it isn't obvious what it will be?
							// anyway i pretty much grab all the non-trival one's, i think because i don't have 0 digits, like the 30/50 in example
							// this below is then meant to check if can simplify, but because they'll always have common factor of 1, and always correct, so just simplifies for me
							// meaning i still get right answer
							int *fract = CanSimplify(arr);
							//cout << "wow" << endl;
							if(fract[0] > 0)
							{
								nonValid[1][counter] = fract[1];
								nonValid[0][counter] = fract[0];
								cout << "oneDown";
								cout << i;
								cout << " ";
								cout << j << endl;
								counter++;
							}
						} 
					}
				}
			}
		}
	}
	float productNum = 1.0;
	float productDenom = 1.0;
	// find product of numerator and denominator seperately
	for(int u=0;u<4;u++)
	{
		cout << "herewego ";
		cout << nonValid[0][u];
		cout << " ";
		cout << nonValid[1][u] << endl;
		productNum *= nonValid[0][u];
		productDenom *= nonValid[1][u];
	}
	// then simplify the acquired fraction
	int *finalFraction = new int[2];
	finalFraction[0] = productNum;
	finalFraction[1] = productDenom;
	finalFraction = CanSimplify(finalFraction);
	cout << finalFraction[1] << endl;
}
