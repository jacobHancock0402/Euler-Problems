#include <iostream>


using namespace std;

int main () {
    int a = 0;
    int b = 0;
    int c = 0;
    for(int j=1;j<1000;j++)
    {
        for(int x=1;x<1000;x++)
        {
            for(int i=1;i<1000;i++)
            {
                int sum = x+j+i;
                if(sum == 1000)
                {
                    if((x*x) + (j*j) == (i*i))
                    {
                        a=x;
                        b=j;
                        c=i;
                    }
                    else if(sum > 1000)
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << a*b*c;
    
}