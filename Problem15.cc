#include <iostream>
#include <string>
#include <map>
#include "InfInt.h"

using namespace std;

// useless function
int Recursion(long long int num, long long int length,long long int maxLength, long long int maxNum)
{
    long long int maxL = maxLength;
    long long int maxN = maxNum;
    while(num < 100)
    {
        length++;
        if(length > maxLength)
        {
            maxLength = length;
            maxNum = num;
        }
        if((num - 1) % 3 == 0)
        {
            Recursion((num - 1) / 3,length,maxL,maxN);
        }
        else
        {
            Recursion(num * 2,length,maxL,maxN);
        }
    }
    return maxNum;
}
// recursion function to count number of paths
InfInt Recurse(int x, int y,InfInt numberPath, int grid_Size, map<string, InfInt>&cachedTiles)
{
    bool finished = false;
    InfInt tileCost = 0;
    string ys = to_string(y);
    string xs = to_string(x);
    string tile = xs + "," + ys;
    // checks if the number of paths from this tile has been counted
    // if it has, then the value is added to the sum and returned
    if(cachedTiles.count(tile) != 0)
    {
        cout << numberPath;
        cout << " ok " ;
        numberPath += cachedTiles[tile];
        //cout<<"wow";
        cout <<numberPath << endl;
        return numberPath;
    }
    // else the function recurses by finding number of paths from(x+1) and (y+1), if valid
    while(finished == false)
    {
        InfInt oldnumberPath = numberPath;
        if(x == grid_Size & y == grid_Size)
        {
            finished = true;
            numberPath++;
            return numberPath;
        }
        if (x + 1 <= grid_Size)
        {
            string ys = to_string(y);
            string xs = to_string(x + 1);
            string tile = xs + "," + ys;
            if(cachedTiles.count(tile) != 0)
            {
                cout << numberPath;
                cout << " ok " ;
                numberPath += cachedTiles[tile];
                //cout<<"wow";
                cout <<numberPath << endl;
            }
            // only calculates the cost of tile if neccesary, improving peformance
            else
            {
                numberPath = Recurse(x + 1,y,numberPath,grid_Size, cachedTiles);
            }
        }
        if(y + 1 <= grid_Size)
        {
            string ys = to_string(y + 1);
            string xs = to_string(x);
            string tile = xs + "," + ys;
            //cout <<cachedTiles.count(tile) << endl;
            if(cachedTiles.count(tile) != 0)
            {
                cout << numberPath;
                cout << " ok " ;
                numberPath += cachedTiles[tile];
                //cout<<"wow";
                cout <<numberPath << endl;
            }
            else
            {
                numberPath = Recurse(x,y + 1,numberPath,grid_Size, cachedTiles);
            }
            //tileCost += (numberPath - oldnumberPath);
        }
        // calculates the cost of the tile for later usage
        // and return the new sum of paths
        tileCost = (numberPath - oldnumberPath);
        //cout << numberPath << endl;
        string xf = to_string(x);
        string yf = to_string(y);
        string str = xf + "," + yf;
        cachedTiles.insert(pair<string, InfInt>(tile, tileCost));
        return numberPath;
    }
    return numberPath;
}
int main() {
    //int number;
    //int chainLength = 0;
    //int greatestVal;
    //int greatestLength;
    //for(int i=9999999;i>0;i--)
    //{
        //number = 11;
        //while(number < 1)
        //{
            //if(number % 2 == 0)
            //{
                //number = number / 2;
            //}
            //else
            //{
                //number = (3 * number) + 1;
            //}
            //chainLength++;
            //cout << number << endl;
        //}
        //cout << chainLength;
        // seems to stop at some point like it's stuck idk why

        //if(chainLength > greatestLength)
        //{
            //greatestVal = i;
        //}
    //}
    //cout << greatestVal;
    // map to store already calculated sums of paths from a tile
    map<string, InfInt> cachedTiles;
    InfInt zero = 0;
    cout << Recurse(0,0,zero,20,cachedTiles);
    
}