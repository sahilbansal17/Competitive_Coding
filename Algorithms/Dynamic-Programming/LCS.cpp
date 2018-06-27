// Program to find Longest Common Subsequence between two strings
// using Dynamic Programming Approach.

// Author: Pritam Negi.

#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int lcs(int idx1, int idx2, vector<char> &v)
{
    // If any string is empty then length of LCS is 0
    if (idx1 == -1 || idx2 == -1)
    {
        return 0;
    }

    if (s1[idx1] == s2[idx2])
    {
        // If character in string s1 at index idx1 
        // matches with character in string s2 at index idx2
        // then that character is part of LCS
        v.push_back(s1[idx1]); 
        return 1 + lcs(idx1 - 1, idx2 - 1, v);
    } 
    else 
    {

        vector<char> v1, v2;

        // If characters in both strings are not same
        // then perfoming LCS calculation for two possibilities
        // In first possibility we are ignoring one character from string s1
        // In second possibility we are ignoeing one character from string s2
        int p1 = lcs(idx1 - 1, idx2, v1); 
        int p2 = lcs(idx1, idx2 - 1, v2);

        if (p1 > p2)
        {
            // If LCS obtained from first possibilty is larger than
            // second possibility then we use this result 
            // we used the characters we already had in v + the ones in v1
            v.insert(v.end(), v1.begin(), v1.end());
            return p1;
        } 
        else
        { 
            // If LCS obtained from second possibilty is larger than
            // first possibility then we use this result
            // we used the characters we already had in v + the ones in v2
            v.insert(v.end(), v2.begin(), v2.end());
            return p2;
        }
    }
}

int main(int argc, const char * argv[])
{
    // Taking first string as input
    cout<< "Enter the first string: ";
    cin>>s1;

    // Taking second string as input
    cout<< "Enter the second string: ";
    cin>>s2;

    // Vector for storing the LCS characters
    vector<char> v;

    int sol = lcs(s1.length() - 1, s2.length() - 1, v); 
    
    cout << "Length of Longest Common Subsequence is: "<< sol << endl;
    reverse(v.begin(), v.end());

    cout<< "Longest Common Subsequence is: ";
    for (auto num : v) {
        cout << num;
    }
    cout<<endl;

    return 0;
}

// Time Complexity: If the length of one string is n and another string is m 
// then complexity of this approach is O(2^(n+m))
// because it test every possible substring of one string with every other substring of another string
// which can be understood by tree or graph representation of recursive calls
// If we take n+m = N then complexity is O (2^N).