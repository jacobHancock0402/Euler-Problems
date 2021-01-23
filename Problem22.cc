#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool compareNames(string name1, string name2) {
    int shortestLength = 0;
    string shortestWord;
    if(name1.length() < name2.length())
    {
        shortestLength = name1.length();
        shortestWord = name1;
    }
    else
    {
        shortestLength = name2.length();
        shortestWord = name2;
    }
    for(int i=0;i<shortestLength;i++)
    {
        if(name1[i] > name2[i])
        {
            return true;
        }
        else if(name1[i] < name2[i])
        {
            return false;
        }
        else if(i == shortestLength - 1)
        {
            if(name1 == shortestWord)
            {
                return false;
            }
            else
            {
                return true;
            }
            
        }
        
    }
    return false;

}

int getScores(string names[], int length) {
    bool sorted = false;
    while(sorted == false)
    {
        int count = 0;
        for(int u=0;u<length - 1;u++)
        {
            bool swapNames = compareNames(names[u], names[u+1]);
            if(swapNames == true)
            {
                string copy = names[u];
                names[u] = names[u+1];
                names[u+1] = copy;
            }
            else
            {
                count++;
            }
            if(count == length - 1)
            {
                sorted = true;
            }

        }
    }
    unsigned long long int score = 0;
    string name;
    for(int j=0;j<length - 1;j++)
    {
        //763333648
        name = names[j];
        int sum = 0;
        for (int y=0;y<name.length();y++)
        {
            sum += (int(name[y]) - 64);
        }
        score +=(sum*(j +1));
        if(j < 5)
        {
            //cout << length << endl;
        }
        cout << j;
        cout << sum;
        cout << "gap";
        cout << score;
        cout << names[j] << endl;
        if(j == length - 3)
        {
            cout << names[j+1];
            cout << names[j+2];
        }
    }
    return score;
}

int main() {
    string text;
    ifstream file("names.txt");
    
    string names[5700];
    while(getline (file, text))
    {
    }
    
    
    int x=0;
    //cout << text ;
    string word;
    //file.close();
    bool brek = false;
    for(long int i=0;i < text.length() - 1;i++)
    {
        //cout << text.length() << endl;
        //cout << text.at(i) << endl;
        word = "";
        while(text[i] != ',')
        {
        
            if(i>text.length() - 1)
            {
                //i++;
                brek = true;
                break;
            }
            if(text[i] != '"')
            {
                word += text[i];
            }
            i++;
        }
        names[x] = word;
        cout << word << endl;
        //cout<<word<<endl;
        x++;
        if(brek == true)
        {
            //cout << i;
            //cout << "lol" << endl; 
            break;
        }
        //cout << i << endl;
        //cout << x << endl;
        //cout << text[i];
    }
    int num_names = x + 1;
    file.close();  
    cout << "***REMOVED***off";
    // this should work, but the program won't let run whole iteration of file 
    // means around 20 chars are left off = slightly inaccurate
    // also needs to sort the list alphabetically , which is very intensive, find good algo
    // this is why value is so small as the list hasn't been sorted
    unsigned long long int scores = getScores(names,num_names);
    cout << scores ;
    //string* name = names;
    //delete[] names;
    //string name[20];
    //for(int i=text.length() - 20;i<text.length() - 1;i++)
    //{
        //word = "";
        //while(text[i] != ',')
        //{
            //if(text[i] != '"')
            //{
                //word += text[i];
            //}
            //i++;
        //}
        //name[x] = word;
        //cout<<word<<endl;
        //x++;
    //}
    //scores += getScores(names,20);
    //cout << scores; 

    // bruh idk ***REMOVED*** this ***REMOVED*** be on, just doesn't work
    // exiting with code big which i thought was for using invalid index
    // now exit code 3 when trying to close file early, no idea., but otherwise value should be pretty good
    
}