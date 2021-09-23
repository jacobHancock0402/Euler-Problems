#include <iostream>
#include <map>

using namespace std;
int main()
{
	// map that stores all the pentagons numbers as keys, used to check if a number is pentagonal
	int upperlim = 10000000000;
	map<int, bool> pentagons;
	map<int, bool> triangles;
	map<int, bool> hexagons;
	// I didnt use the formula, instead i noticed that the difference between numbers increases by 3 each time, with it starting at 4
	int additive1 = 4;
	int additive3 = 2;
	int additive2 = 5;
	pentagons[1] = true;
	hexagons[1] = true;
	triangles[1] = true;
	int numP = 1;
	int numH = 1;
	int numT = 1;
	// the limit is arbitrary. I increased by power of 10 until i found a solution
	int limit = 100000;
	// this stores all of the keys as an array
	int* keysH = new int[limit];
	int* keysP = new int[limit];
	int* keysT = new int[limit];
	keysH[0] = 1;
	keysP[0] = 1;
	keysT[0] = 1;
	// here we get all the pentagonal numbers up to the limit
	for(int i=1;i<limit;i++)
	{
		pentagons[numP + additive1] = true;
		keysP[i] = numP + additive1;
		numP = keysP[i];
		triangles[numT + additive3] = true;
		keysT[i] = numT + additive3;
		numT = keysT[i];
		hexagons[numH + additive2] = true;
		keysH[i] = numH + additive2;
		numH = keysH[i];
		additive1 += 3;
		additive2 += 4;
		additive3 += 1;
		//cout << additive2 << endl;
	}
	//cout << hexagons.count(40755) << endl;
	// cout << keysH[1] << endl;
	// cout << keysH[2] << endl;
	// cout << keysP[1] << endl;
	// cout << keysP[2] << endl;
	// cout << keysT[1] << endl;
	// cout << keysT[2] << endl;
	for(int i=40756;i<keysT[limit - 1];i++)
	{
		cout << i << endl;
		if(hexagons.count(i) > 0)
		{
			if(pentagons.count(i) > 0)
			{
				if(triangles.count(i) > 0)
				{
					cout<< upperlim << endl;
					exit(0);
				}
			}
		}
	}
}
	