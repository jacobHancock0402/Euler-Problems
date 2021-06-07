#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float width = 1001.00;
    float height = 1001.00;
    // dynamic 2d array so space isn't constrained
    auto spiral = new double[1001][1001];
    // the first coordinate is set to center but one to right
    int x = (int)round(width/2.00);
    int y = (int)round(height/2.00) - 1;
    //first value of is already placed so 2 will be set on 1st tile
    int value = 2;
    // array is initiliazied with zeroes to check if they've been assigned a value yet
    for(int f=0;f<width;f++)
    {
        for(int h=0;h<height;h++)
        {
            spiral[f][h] = 0;
        }
    }
    // center tile is set to 1
    spiral[(int)round(width/2.00) - 1][(int)round(height/2.00) - 1] = 1;
    // construction of spiral
    while(true)
    {
        // follows a 4 move pattern
        for(int i=0;i<4;i++)
        {
            // 1st move = move down until tile 2 the left hasn't been assinged
            if(i == 0)
            {
                while(spiral[x - 1][y] > 0 && (x - 1) >= 0)
                {
                    spiral[x][y] = value;
                    y++;
                    value++;
                }
            }
            // 2nd move = move left until tile above hasn't been assigned
            else if(i == 1 && (y - 1) >= 0)
            {
                while(spiral[x][y - 1] > 0)
                {
                    spiral[x][y] = value;
                    x--;
                    value++;
                }
            }
            // 3rd move = move up until tile to the right hasn't been assigned
            else if(i == 2 && (x + 1) < width)
            {
                while(spiral[x + 1][y] > 0)
                {
                    spiral[x][y] = value;
                    y--;
                    value++;
                }
            }
            // 4th move = move right until tile below hasn't been assinged
            else if((y + 1) < height)
            {
                while(spiral[x][y + 1] > 0)
                {
                    // if construction complete, break
                    if(x == width - 1 && y == 0)
                    {
                        spiral[x][y] = value;
                        break;
                    }
                    spiral[x][y] = value;
                    x++;
                    value++;
                }
            }
        }
        // if construction complete, break
        if(x == width - 1 && y == 0)
        {
            break;
        }
    }
    int newX = 0;
    int newY = 0;
    int intHeight = (int)height;
    int intWidth = (int)width;
    int sum = 0;
    int f = 0;
    // south east diagonal calculation
    while(f < width)
    {
        // if reached bottom right corner then break
        if(newX >= intWidth && newY >= intHeight)
        {
            break;
        }
        // else sum this tile and move one to right and one down to continue the diagonal
        else if(newX < width && newY < width)
        {
            sum += spiral[newX][newY];
            //cout << sum << endl;
            newX++;
            newY++;
        }
        f++;
    }
    newX = 0;
    newY = intHeight - 1;
    f=0;
    // northwest diagonal calculation
    while(f<width)
    {
        // if reached top right corner then break
        if(newX >= intWidth && newY < 0)
        {
            break;
        }
        // else sum the tile
        else if(newY >= 0 && newX < width)
        {
            // but don't same if value is 1, as this is the center tile == only tile which both diagonals cross = already counted
            if(spiral[newX][newY] > 1)
            {
                sum += spiral[newX][newY];
            }
            newX++;
            newY--;
        }
        f++;
    }
    // sum is outputted
    cout << sum;
    return 0;
}