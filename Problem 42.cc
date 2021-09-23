#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;
// function to get the score of a character
int getWordScore(string word, map<char, int> scores)
{
	int score = 0;
	// goes through each character and sum their scores
	for(int i=0;i<word.length();i++)
	{
		// scores is a dictionary that has mapped all the alphabet to a numbers, so A = 1, B = 2 ect.
		score += scores[word.at(i)];
	}
	return score;
}
int main()
{
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map<char, int> scores;// = new map<char,int>()
	// mapping scores by setting the character's key to it's index + 1, so then it scores start from 1 at A
	for(int j=0;j<alphabet.length();j++)
	{
		scores[alphabet.at(j)] = j+1;
	}
	string text;
	ifstream file("words.txt");
    // grabbing the file and placing it in a string
    string words[2000];
    int words_score[2000];
    int greatestScore = 0;
    while(getline (file, text))
    {
    }
    int x = 0;
    // formating the string into a list, by defining a words as the non quotes between commas
    for(int i=0;i<text.length();i++)
    {
    	bool brek = false;
    	string word = "";
    	// so we collect the character and append to the word at this index, then create a new word when hit a new comma, as a new one starts
    	while(text[i] != ',')
    	{
            if(i>text.length() - 1)
            {
                brek = true;
                break;
            }
            if(text[i] != '"')
            {
                word += text[i];
            }
            i++;
        }
        // scores are generated
        words[x] = word;
        words_score[x] = getWordScore(word, scores);
        // i find the max score so then i only have to calculate a specific number of triangular numbers
        if(words_score[x] > greatestScore)
        {
        	greatestScore = words_score[x];
        }
        x++;
        if(brek == true)
        {
            break;
        }
    }
    int triangle = 1;
    int triangles = 0;
    int n = 1;
    int *triangularNumbers = new int[100];
    // this just uses the triangular number formula up to our limit
   	while(triangle < greatestScore)
   	{
   		triangle = 0.5*n*(n+1);
   		triangularNumbers[n - 1] = triangle;
   		n++;
   	}
   	// here we check if the word has a score of a triangular numbers
   	// done by looping through every word and checking it's score against the triangular numbers
   	// if it does match, then triangles is incremented
   	for(int i=0;i<x;i++)
   	{
   		for(int j=0;j<n;j++)
   		{
	   		if(words_score[i] == triangularNumbers[j])
	   		{	   			
	   			triangles++;
	   			break;
		   	}
	   	}
   	}
   	// the number of matches is output
   	cout << triangles << endl;
	return 0;
}