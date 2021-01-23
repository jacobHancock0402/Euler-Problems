#include <iostream>

using namespace std;

int main() {

    int regyears = 0;
    int leapyears = 0;
    int gap = 365;
    bool leapyear = false;
    int count = 0;
    int month = 1;
    int debutDays[12] = {1,32,60,91,121,152,182,213,244,274,305,335};
    int totaldays = (76*365) + (24*366);
    for (int i=1;i<totaldays;i++)
    {
        bool monthDebut = false;
        bool counting = true;
        int years = i / 365;
        gap++;
        if(years % 4 == 0 && gap > 366 && i > 366)
        {
            leapyears++;
            gap = 0;
        }
        if(gap < 365)
        {
            leapyear = true;
        }
        regyears = years - leapyears;
        //cout << regyears;
        //cout << "years" ;
        //cout << years << endl;
        int goneDays = ((regyears * 365) + (leapyears * 366));
        int thisyearsDays = i - goneDays;
        //cout << goneDays ;
        //cout << "i";
        //cout << i;
        //cout << "how";
        //cout << i - goneDays;
        //cout << "ok";
        if(i<366)
        {
            counting = false;
            thisyearsDays = i;
        }
        if((i % 7 == 0))
        {
            for(int j=0;j<11;j++)
            {
                if(thisyearsDays == debutDays[j] || (thisyearsDays == 61 && leapyear == true))
                {
                    count++;
                    break;
                }
            }
        }
        //cout << thisyearsDays << endl;
        
    }
    cout << count;
    return 0;
    // value about 100 off, many things could be wrong in terms of numbers, but genernal method should be fine



}