#include <iostream>

using namespace std;

int main()
{
	int *pentagons = new int[1000];
	int additive = 4;
	pentagons[0] = 1l
	for(int i=1;i<1000)
	{
		pentagons[i] = pentagons[i-1] + additive;
		cout << pentagons[i] << endl;
		additive += 3;
	}
}