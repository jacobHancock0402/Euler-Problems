#include <iostream>

using namespace std;
int numbers[4000000];
int main() {
    numbers[0] = 1;
    numbers[1] = 2;
    int sum = 0;
    int i = 2;
    cout << "bad" ;
    while (sum <= 4000000)
    {
        sum = numbers[i - 2] + numbers[i - 1];
        numbers[i] = sum;
        i++;
    }
    cout << "good";
    int total = 0;
    for (int j=0;j<(sizeof(numbers) / sizeof(*numbers));j++)
    {
        int number = numbers[j];
        if(number % 2 == 0 && number <= 4000000)
        {
            total += number;
        }
        
    }
    cout << total;
    return 0;

}