#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <math.h>

using namespace std;
class DivisorReturn {
	public : 
	int *divisors;
	int length;
};
DivisorReturn GetDivisors(long long int number)
{
    int i = 1;
    int divisorCount = 0;
    int counter = 0;
   	int *divisors = new int[50];
   	//list<int>::iterator it = divisors.begin();
    // cout << "number ";
    // cout << number << endl;
    //cout << "wow" << endl;
    // only counts to the square roots as that is the max divisor
    // higher divisor will be counted by the 2* at end from the fact divisors occur in pairs
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
	        // cout << counter;
	        // cout << " ";
	        // cout << number/i;
	        // if((number % i) == 0)
	        // {
	        	//cout << "twat";
	            divisors[counter] = i;
	            divisors[counter+1] = i;
	            // cout << number;
	            // cout << " ";
	            // cout << number/i << endl;
	            counter+=2;
	        // }
	        i++;
	    }
	}
    // the divisors occur in pairs i.e 2 * 28 = 56, so we count 2 but not 28
    // so we just multiply by 2 to get the total
    cout << "***REMOVED***";
  	DivisorReturn divisorRet;
  	divisorRet.divisors = divisors;
  	divisorRet.length = counter;
    return divisorRet;
}
int* CanSimplify(int arr[])
{
	cout << "gogetme" << endl;
	DivisorReturn iRet = GetDivisors(arr[0]);
	DivisorReturn jRet = GetDivisors(arr[1]);
	cout << "lo" ;
	int iLen = iRet.length;
	int jLen = jRet.length;
	int *iDivisors = iRet.divisors;
	int *jDivisors = jRet.divisors;
	cout << iDivisors[0];
	//cout << "wedidit" << endl;
	int counter = 0;
	bool sorted = false;
	int *array = new int[2];
	// dik what's happening here
	// not sure if related to the errors
	// just errors in loop at 16 when trying to grab the thing
	// this is because that's when it enters here
	// so assuming it's cause this error
	// idk why though;
	// have to rework this
	// this might work with some adjustements
	cout << "fat";
	// seemingly infinte loop on first loop, prob from functions
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
	cout << "***REMOVED***";
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
	array[0] = 0;
	return array;

}
int main()
{
	int counter = 0;
	float nonValid[2][4];
	for(int i=1;i<100;i++)
	{
		//cout << "***REMOVED***" << endl;
		for(int j=1;j<100;j++)
		{
			if(j>i)
			{
				int idig1 = i % 10;
				int idig2 = (i/10) % 10;
				int jdig1 = j % 10;
				int jdig2 = (j/10) % 10;
				int *newDigi = new int[4];
				int *newDigj = new int[4];
				int count = 0;
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
						int thisDigi = newDigi[w];
						int thisDigj = newDigj[w];
						//cout << newDigi[w] << endl;
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
						if(digiDiv == ijDiv)
						{
							//cout << "yeah" << endl;
							int *arr = new int[2];
							arr[0] = thisDigi;
							arr[1] = thisDigj;
							//cout << "boys" << endl;
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
	for(int u=0;u<4;u++)
	{
		cout << "herewego ";
		cout << nonValid[0][u];
		cout << " ";
		cout << nonValid[1][u] << endl;
		productNum *= nonValid[0][u];
		productDenom *= nonValid[1][u];
	}
	cout << productDenom << endl;
}
