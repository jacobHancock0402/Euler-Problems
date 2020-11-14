#include <iostream>


using namespace std;

int main () {
    int a = 0;
    int b = 0;
    int c = 0;
    for(int j=1;j<30;j++)
    {
        for(int x=1;x<30;x++)
        {
            for(int i=1;i<30;i++)
            {
                int sum = x+j+i;
                if(sum == 12)
                {
                    if((x*x) + (j*j) == (i*i))
                    {
                        a=x;
                        b=j;
                        c=i;
                    }
                    else if(sum > 12)
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << a;
    cout << b;
    cout << c;
}