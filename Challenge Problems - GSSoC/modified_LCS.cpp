/*
Given:
n strings of length m consisting of only 'a' and 'b' as characters.
a hidden string of length m (this can be any string consisting of 'a' and 'b')

Tasks:

Calculate the least value of the Longest Common Subsequence of the given n strings and the hidden string.
Sample:
2 given strings:
ab
ba
The hidden string can be (aa,ab,ba,bb). The LCS for all cases is equal to 1. Hence the answer is 1.
*/
#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int n, m;
	cout << "Enter number of strings = ";
	cin >> n;
	cout << "Enter length of string = ";
	cin >> m;
	string input;
	// min_a stores the minimum of the count of 'a' of all the input strings
	int min_a = INT_MAX, min_b = INT_MAX, count_a, count_b;
	cout << "Enter strings" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>input;
		// counting the number of 'a' and 'b' in current string
		count_a = 0, count_b = 0;
		for (int j = 0; j < m; ++j)
		{
			if(input[j] == 'a')
			{
				count_a++;
			}
			else 
			{
				count_b++;
			}
		}
		min_a = min(min_a, count_a);
		min_b = min(min_b, count_b);
	}
	// ans would be minimum of min_a and min_b
	cout << min(min_a, min_b) <<endl;
}
// Explanation :
// For proving this algorithm we first prove that min_a + min_b <= m.
// Suppose this is not true so min_a + min_b must be greater than m.
// Now, min_a + min_b > m  =>  min_b > m - min_a  --- (1)
// But for the input string which has min_a 'a' we'll have min_a + x 'b' = m (where x denotes the number of 'b')
// as each string has length m and consists only of 'a' or 'b'. 
// So x = m - min_a. But from (1) we have min_b > m - min_a.So x < min_b .This is a 
// contradiction as min_b must be the minimum count of 'b' of all input strings.
// Hence our assumption is wrong.
// So min_a + min_b <= m

// Now moving to the proof of the algorithm. Without loss of generality suppose min_a < min_b.
// So according to our algorithm answer must be min_a.If we consider the hidden string having only 'a' then 
// it would indeed have min_a number of 'a' common with all input strings as each input string has atleast
// min_a 'a'.So we have fixed an upper bound on answer.

// Suppose our algorithm is wrong and answer must be less than min_a. Now the hidden string must have less than 
// min_a 'a' otherwise there would be a longer common subsequence as each input string has atleast min_a 'a'. 
// Let number of 'a' in hidden string be x and number of 'b' be y.
// x + y = m  =>  min_a + y > m (As x < min_a)  =>  y > m - min_a 
// But we have already proved min_a + min_b <= m  =>  min_b <= m - min_a < y => min_b < y
// This means the hidden string and input strings have min_b 'b' common. So the sequence of 'b' is a 
// common subsequence.So answer must be at least min_b.This means answer >= min_b.But min_b > min_a.
// So answer > min_a which is a contradiction.Hence our assumption is wrong .Therefore answer must be min_a.
// So our algorithm is correct

// Time complexity : O(mn) as we have a nested loop.Outer loop runs n time and inner loop runs m times.
// Space complexity : O(1) 