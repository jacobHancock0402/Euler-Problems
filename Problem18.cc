#include <iostream>
#include <map>
#include <string>

using namespace std;
int Recurse(int row, int column, int total, int rows[][15], int greatest_Total, map<string, int>&maxSum) {
    // adds the number on this tile to the total in this path
    total += rows[row][column];
    // this is a temporary variable to calculate the max sum of future path and check against largest path
    int newTotal = total;
    //cout << total << endl;
    //string name = to_string(row) + to_string(column);

    //cout << "col";
    //cout << column ;
    //cout << "row";
    //cout << row 
    //cout << rows[row][column]
    //if(maxSum.count(name)> 0)
   // {
        //if(maxSum[name] > greatest_Total)
        //{
           // return maxSum[name];
        //}
        //else
        //{
        //}
            
            //return maxSum[name];
    //}
    // recurse until we have reached the final row
    if(row + 1 < 15)
    {
        // finds the individual sums of the two different paths you could take down the triangle
        // you could either go diagonal right, representing column + 1 in array
        // or column in the array, which is calculated below this calculation
        newTotal = Recurse(row + 1,column + 1,total,rows,greatest_Total,maxSum);
        cout << newTotal << endl;
        // if this path is the greatest so far, it recognized and the value is stored
        if(newTotal > greatest_Total)
        {
            greatest_Total = newTotal;
        }
            //cout << total << endl;
        // the caculation for row+1, column
        newTotal = Recurse(row + 1,column,total,rows,greatest_Total,maxSum);
        if(newTotal > greatest_Total)
        {
            greatest_Total =  newTotal;
        }
    }
    // if we are at the bottom row, we just return the total, which is sum of path + this tile
    else
    {
        return total;
    }
    // greatest path sum from this tile is returned
    //maxSum[name] = greatest_Total;
    // i tried to store the max sum from each tile in an array to improve performance
    // but i couldn't get it to work and the time to do so didn't seem to be worth the small boost in time to run
    return greatest_Total;

}

int main() {
    string words = "75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
    cout << words << endl;
    int counter = 0;
    int n = 0;
    // how we store the triangle
    int rows[15][15];
    int x = 0;
    int y = 0;
    int whileCount = 0;
    int length = words.length();
    // loops through each character
    for(int i=0;i<length;i++)
    {
        whileCount = 0;
        // collects each character in pairs until whitespace, then moves to the next
        while(!isspace(words[i]))
        {
            // this checks if this index is empty
            // if so we just set it to the int of the char
            if(whileCount == 0)
            {
                rows[n][y] =  (words[i] - '0');
                whileCount++;
            }
            // else, we multiply the value by 10 and add the character
            // the conditions are needed to ensure were not multiplying any addresses or anything
            // as this would be the case if index was empty
            // the logic i used to append an int to int is used in previous problems
            else
            {
                rows[n][y] = (rows[n][y] * 10) + (words[i] - '0');
            }
            // while loop exits if where on last char as there's no whitespace there
            // this means it would try and access an index outsdie the string = error
            if(i == length - 1)
            {
                break;
            }
            i++;
            
        }
        // row n has n columns so we collect pairs from string until we have n pairs to put in row n
        if(counter == n)
        {
            counter = 0;
            y = 0;
            n++;
            x++;
        }
        // else we keep collecting pairs for this row
        else
        {
            counter++;
            y++;
        }
    }
    map<string,int>maxSum;
    // then we use the recurse function to find the maxPathSum;
    cout << Recurse(0,0,0,rows,0,maxSum);

    return 0;
}