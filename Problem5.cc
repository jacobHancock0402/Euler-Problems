#include <iostream>

using namespace std;

int main() {
    int i = 1;
    bool done = false;
    while(done == false)
    {
        if(i % 2 != 0 || i % 3 != 0 || i % 2 != 0 || i % 3 != 0 || i % 4 != 0 || i % 5 != 0 || i % 6 != 0 || i % 7 != 0 || i % 8 != 0 || i % 9 != 0 || i % 10 != 0 || i % 11 !=0 || i % 12 !=0 || i % 13 != 0 || i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 || i % 18 != 0 || i % 19 != 0 || i % 20 != 0)
        {
            done = false;
        }
        else
        {
            done = true;
            break;
        }
        i+=1;
    }
    /*int x = 0;
    int values[450];
    cout << "hyah";
    for(int i=20;i>1;i--)
    {
        for(int j=20;j>1;j--)
        {
            values[x] = i * j;
            x++;
        }
    }
    cout << "getem";
    int length = sizeof(values) / sizeof(*values);
    bool sorted = false;
    int count = 0;
    cout << "die";
    cout << length;
    while(count != length - 1)
    {
        count = 0;
        for(int y=0;y<length - 1;y++)
        {
            if(values[y] > values[y+1])
            {
                int copy = values[y];
                values[y] = values[y + 1];
                values[y+1] = copy;
            }
            else
            {
                count++;
            }
        }
    }
    int counter = 0;
    for(int e=0;e<length;e++)
    {
        cout << values[e] << endl;
    }
    for(int u=0;u<length - 1;u++)
    {
        cout << counter;
        if(counter >= 20)
        {
            cout << values[u - 1];
            return 0;
        }
        else if(values[u] == values[u+1] && values[u] != 0)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        
    }
    */
   cout << i ;
    return 0;
}