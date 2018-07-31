// The Rabin-Karp algorithm makes use of hash functions and the rolling hash technique. Rolling hash allows 
// us to calculate a hash value without having the rehash the entire string. In case of a mismatch of hash values 
// of pattern and substring we can be sure that pattern doesn't match with the substring. This would avoid checking
// the whole substring by iterating through it and hence would improve the performance drastically. Also if a good
// hash function is chosen then it would avoid hash collisions.

// Hash function generally used in Rabin-Karp Algorithm
// H[1..3] = c1*26^2 + c2*26 + c3
// Now if we want to calculate H[2..4] then H[1..3] can be used
// H[2..4] = (H[1..3] - c1*26^2) * 26 + c4
// Take modulo with a large prime number at each step to avoid integer overflow

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string text, pattern;
	cout << "Enter Text ";
	cin >> text;
	cout << "Enter pattern ";
	cin >> pattern;
	std::vector<int> ans;
	// hash_t stores hash of the substring of the text being considered
	// hash_p stores hash of the pattern
	long long int hash_p = 0, hash_t = 0, flag =0 ,mul = 1, MOD = 1e9 + 7;
	int pattern_length = pattern.length(), text_length = text.length();
	
	// Calculating the hash for pattern and hash for substring starting at 0th index of text 
	// and having length = pattern_length
	for (int i = pattern_length - 1; i >= 0; --i)
	{
		hash_p = ( hash_p + (mul * pattern[i]) %MOD ) % MOD;
		hash_t = ( hash_t + (mul * text[i]) %MOD ) % MOD;
		// set flag to 1 in case of a mismatch
		if(text[i] != pattern[i])
		{
			flag = 1;
		}
		mul = (mul * 26)%MOD;
	}
	mul /= 26;
	// mul stores 26^(pattern_length-1)

	if(flag == 0)
	{
		ans.push_back(0);
	}
	
	for (int i = 1; i <= text_length - pattern_length ; ++i)
	{
		// Current substring = text[i..i+pattern_length-1]

		// Using the hash value of previous substring to calculate hash of new substring
		// Removing the (i-1)th element and adding (i + pattern_length - 1)th element
		hash_t = (hash_t - (text[i - 1] * mul) % MOD + MOD) % MOD;
		hash_t = (hash_t * 26) % MOD;
		hash_t = (hash_t + text[i + pattern_length - 1]) % MOD;
		if (hash_t == hash_p)
		{
			// If hash values of substring and pattern match check if each character is same
			// by running a for loop
			flag = 0;
			for (int j = i; j < i + pattern_length ; ++j)
			{
				if(text[j] != pattern[j - i])
				{
					// Set flag to 1 in case of a mismatch
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				ans.push_back(i);
			}
		} 
	}
	for (auto &x : ans)
	{
		cout << x << " ";
	}
	return 0;
}
// Considering pattern_length = m, text_length = n

// Time Complexity : The outer for loop runs (n - m + 1) times. The inner for loop runs in case of matching of
//                   hash value. Suppose there are r matches. Then the complexity would roughly be O(n + mr).
//                   In case of n - m + 1 matches the complexity would become O(nm) which is the worst case
//                   of this algorithm.

// Space Complexity : ans vector stores only indices in case of match. So auxiliary space required is 
//                    O(number_of_matches).
