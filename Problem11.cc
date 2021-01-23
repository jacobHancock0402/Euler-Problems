#include <iostream>

using namespace std;

int main() {
    string value = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ";
    string grid[20][20];
    int x = 0;
    string str = "";
    // 2 loops that creates a 2d array to represent the 20x20 grid
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            str = "";
            // collects all characters and appends it to a string
            while(!isspace(value[x]))
            {
                str += value[x];
                x++;
            }
            x++;
            //cout << str << endl;
            // string is then set as value for this grid position
            // loop repeats at character past space
            grid[i][j] = str;
        }
    }
    int largestProduct = 0;
    // finds the largest product
    for(int x=0;x<20;x++)
    {
        for(int y=0;y<20;y++)
        {
            int productY = 1;
            int productX = 1;
            int productXYDown = 1;
            int productXYUp = 1;
            bool xValid = false;
            bool yValid = false;
            // bunch of conditions to check wether a valid 4 number long product can be made in each direction
            // we do not need to check the opposite directions of x and y
            // because the same product will be calculated at a different tiles in opposite direction
            // as multiplication is commutative
            // vert check
            if(y+3 < 20)
            {
                for(int z=0;z<4;z++)
                {
                    // the value must be converted from string to int
                    // i'd have preffered to have used int's in the beginning for array, as this would increase performance
                    // but that would be values such as 08 couldn't be stored correctly
                    productY = productY * stoi(grid[x][y+z]);
                }
                yValid = true;
            }
            // horiz check
            if(x+3<20)
            {
                for(int f=0;f<4;f++)
                {
                    productX = productX * stoi(grid[x][y+f]);
                }
                xValid = true;
            }
            // diag up check
            if(yValid && xValid)
            {
                for(int s=0;s<4;s++)
                {
                    productXYDown = productXYDown * stoi(grid[x+s][y+s]);
                }
            }
            // diag down check
            // we must check 2 diags because the diags are perpendicular, not parallel like would be in opposite directions
            if(xValid && y-3>=0)
            {
                for(int e=0;e<4;e++)
                {
                    productXYUp = productXYUp * stoi(grid[x+e][y-e]);
                }
            }
            // checks to see if any product starting from this tile is greater than the largest product so far
            // if so, it is set to greatestProduct
            if(productXYUp > largestProduct)
            {
                largestProduct = productXYUp;
            }
            if(productXYDown > largestProduct)
            {
                largestProduct = productXYDown;
            }
            if(productX > largestProduct)
            {
                largestProduct = productX;
            }
            if(productY > largestProduct)
            {
                largestProduct = productY;
            }

            
        }
        cout << largestProduct << endl;
        cout << x << endl;
    }

    cout << largestProduct;
    return 0;
}