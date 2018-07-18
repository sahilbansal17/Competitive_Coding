// The idea behind the KMP algorithm is recovering from mismatches by using partial match information to skip
// over position where pattern can't be found and avoiding comparisons where we know that a prefix of the pattern
// already exists.
// Suppose the pattern is ACBAE and the text is like ACBAC.... . Now if we start moving from the 1st index of the 
// text there would be a mismatch when we reach 'C' . If we used the naive algorithm then we had to go back to the 
// 2nd index of the text and start comparisons from the beginning. This is avoided by the KMP algorithm.

// The pattern would not be found at the 2nd index as it doesn't start with 'C'.Same is true for the third index.
// But the pattern can be found starting at the 4th index as it starts with 'AC' .So we must start comparing
// the 3rd index of pattern with the next index of the text.
// This is what the lps array stores.The position of the pattern which must be compared with the next index incase 
// of a mismatch at next index of pattern. This is equivalent to the length of the longest prefix which is equal 
// to a suffix in the current portion. This way if we have precomputed the lps array then the pattern can be found 
// in single traversal of the text.

#include <iostream>
#include <vector>
using namespace std;
std::vector<int> lps;
void preprocess(string s)
{
	// j denotes the length of longest suffix which matches a prefix 
	int len = s.length(), j = 0;
	// lps[0] is always 0 as incase of mismatch with the 1st index we must start comparisons from
	// the 0th index of the pattern
	lps.push_back(0);
	for (int i = 1; i < len; ++i)
	{
		// In case of mismatch at next position next index of text must be compared with the s[j + 1]
		// as prefix of length j is equal to suffix of length j
		if(s[i]==s[j])
		{
			j++;
			lps.push_back(j);
		}
		else
		{
			// If we're still at the beginning of the pattern and there's a mismatch then next index must be 
			// compared with the 0th index of the pattern as there is no prefix which is equal to suffix
			if(j == 0)
			{
				lps.push_back(0);
			}
			else
			{
				// Find smaller suffix which is equal to prefix
				while(j > 0 && s[i] != s[j])
				{
					j = lps[j-1];
				}
				// If there's a suffix which is equal to prefix then the next index must be compared with the next
				// index of the prefix.So increment j
				if(s[i] == s[j])
				{
					j++;
				}
				lps.push_back(j);
			}
		}
	}
	return;
}
int main()
{
	string text, pattern;
	cin >> text;
	cin >> pattern;
	// Pre-processing the pattern
	preprocess(pattern);
	int text_length = text.length(), pattern_length = pattern.length();
	// cur denotes the current index of the pattern
	int cur = 0;
	for (int i = 0; i < text_length; ++i)
	{
		// If the current indices of the pattern and text match then increment the index of pattern
		if(text[i] == pattern[cur])
		{
			cur++;
		}
		else 
		{
			// pattern[0..cur-1] matched with the text so move the pattern pointer to lps[cur - 1] and current index
			// must be compared with lps[cur - 1], so decrement i, to balance the increment due to for loop.
			if(cur != 0)
			{
				cur = lps[cur - 1];
				i--;
			}
		}
		// if the pattern fully matched with the text then print the starting point of the pattern and move the cur pointer
		// to lps[cur - 1] to find other occurences of the pattern
		if(cur == pattern_length)
		{
			cout << i - cur + 1 << " ";
			cur = lps[cur - 1];
		}
	}
	return 0;
}
// Considering n = text_length, m = pattern_length

// Time Complexity :
// Pre-processing - O(m)
//                  The outer for loop runs m times. In each iteration j can either increase by 1 or decrease. During
//                  decrement in the worst case it can become 0. Also j can never exceed i.So j can decrease at most 
//                  as often it has been incresed by j++ which happens at most m times. So overall complexity becomes 
//                  O(2m) which is O(m).
// Searching - O(n)
//             The loop for searching runs n times. So time complexity is O(n).

// Space Complexity : O(m)
//                    The space required by the lps array is O(m).