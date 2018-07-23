// Program to find all occurrences of a 
// pattern string within a text string
// using Naive String Matching Algorithm.

// Author: Pritam Negi.

#include<iostream>
#include<string>
using namespace std;

// Function to find the pattern string within the text string
void NaiveStringMatching(string text, string pattern)
{
    // Getting the length of pattern string
    int pattern_length = pattern.length();

    // Getting the length of text string
    int text_length = text.length();
    int flag = 0;

    // Loop to trace the complete text string
    for (int text_iterator = 0; text_iterator <= text_length - pattern_length; text_iterator++)
    {
        int pattern_iterator;

        // For current index i, check for pattern match 
        for (pattern_iterator = 0; pattern_iterator < pattern_length; pattern_iterator++)
        {
            if (text[text_iterator + pattern_iterator] != pattern[pattern_iterator])
            {
                break;
            }
        }

        if (pattern_iterator == pattern_length) 
        {
            cout<< "Pattern string found at position "<< text_iterator<< endl;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        cout<< "Pattern string not found in the text string";
    }
}

int main()
{
    string text, pattern;

    // Taking text string as input
    cout<< "Enter the text string: ";
    cin>> text;

    // Taking pattern string as input
    cout<< "Enter the pattern to search for: ";
    cin>> pattern;

    NaiveStringMatching(text, pattern);

    return 0;
}

// Time Complexity: Best case for this algorithm occurs when the first character of the pattern
// string does not occur in the text string. In that case complexity is O(text_length).
// Worst case occurs for this algorithm occurs when all characters of pattern string
// and text string match. In that case complexity is O((text_length - patter_length) * pattern_length).
