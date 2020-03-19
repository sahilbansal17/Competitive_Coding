#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

// REFERENCE:
// https://leetcode.com/problems/shortest-palindrome/discuss/60204/using-kmps-lps-longest-prefix-suffix-computation-to-solve-in-linear-on-time

int longest_palindrome_prefix(string s) {
    /**
     * The LPS computation can determine, at any given index i in a string S, the maximum suffix length that
     * make up a suffix equal to the prefix. For example: S = "acexxxaceyyy": at S[6], S[7], and S[8] will be
     * marked with "1", "2", and "3" respectively because "a", "ac", and "ace" at this points in the string
     * make up substrings whose suffixes equal to the string's prefix. This computation can be done in one
     * linear scan of the string in O(N) time, using a secondary integer array in O(N) space.
     * 
     * For our purpose in finding the longest palindrome prefix of a string, the idea is simple:
     * if we reverse the string, then appending it to the original string (after a special marker),
     * the palindromic prefix will show up at the end of the compound string! If we then apply the above algorithm,
     * by the end of the linear scan, we'll have a number that correspond to the maximum suffix length of
     * the entire compound string, which correspond to a suffix = prefix. And since a palindromic prefix, when
     * reversed and appended, will show up as the suffix, we will conveniently have computed the maximum
     * length of the palindromic prefix!
     * 
     * For example: consider the string S = "abbaaax". The longest palindrome prefix is "abba".
     * 1. Create S' = "abbaaax#xaaabba"
     * 2. Compute LPS: lps[] = { 0,  0,  0,  1,  1,  1,  0,  0,  0,  1,  1,  1,  2,  3,  4 }
     *            from  S'[] = {'a','b','b','a','a','a','x','#','x','a','a','a','b','b','a'}
     * 3. The last element of LPS, 4, is our longest palindrome prefix length!
     */
    if (s.length() <= 1) {
        return s.length();
    }
    string kmprev = s;
    reverse(kmprev.begin(), kmprev.end());
    string kmp = s + "#" + kmprev;

    vector<int> lps(kmp.size(), 0);   // lps[i] = longest suffix length for substring kmp[0..i] where the suffix == prefix
    for (int i = 1; i < (int)lps.size(); ++i) {
        int prev_idx = lps[i - 1];
        while (prev_idx > 0 && kmp[i] != kmp[prev_idx]) {
            prev_idx = lps[prev_idx - 1];
        }
        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }
    // after KMP's LPS preprocessing, the last index of the LPS array will contain the longest palindrome prefix' length!
    return lps[lps.size() - 1];
}

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    string s;
    while (t--) {
        cin >> s;

        int l[5];
        string ans[5];
        int n = s.length();
        l[1] = longest_palindrome_prefix(s);
        ans[1] = s.substr(0, l[1]);

        string rev = s;
        reverse(rev.begin(), rev.end());
        l[2] = longest_palindrome_prefix(rev);
        ans[2] = rev.substr(0, l[2]);

        int pre = 0;
        int suf = n - 1;
        int len = 0;
        while (pre != suf && s[pre] == s[suf]) {
            ++pre;
            --suf;
            len += 2;
        }
        if ((pre == 0 && suf == n - 1) || pre >= suf) {
            if (l[1] >= l[2]) {
                cout << ans[1] << endl;
                continue;
            } else {
                cout << ans[2] << endl;
                continue;
            }
        }
        string s2 = s.substr(pre, suf - pre + 1);

        l[3] = longest_palindrome_prefix(s2);
        ans[3] = s.substr(0, pre) + s2.substr(0, l[3]) + s.substr(suf + 1);
        l[3] = ans[3].length();

        string rev2 = s2;
        reverse(rev2.begin(), rev2.end());
        l[4] = longest_palindrome_prefix(rev2);
        ans[4] = s.substr(0, pre) + rev2.substr(0, l[4]) + s.substr(suf + 1);
        l[4] = ans[4].length();

        string ANS;
        for (int i = 1; i <= 4; ++i) {
            bool poss = true;
            for (int j = 1; j <= 4; ++j) {
                if (l[i] < l[j]) {
                    poss = false;
                }
            }
            if (poss && ans[i].length() > ANS.length()) {
                ANS = ans[i];
            }
        }
        cout << ANS << endl;
    }
    
    return 0;
}