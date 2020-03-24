// https://practice.geeksforgeeks.org/problems/maximum-sub-string-after-at-most-k-changes/0

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string& s, char ch, int k) {
    int n = s.length();
    int l = 0;
    int r = 0;
    int cnt = 0;
    int maxi = 0;
    while (r < n) {
        if (s[r] != ch) {
            ++cnt;
        }
        while (cnt > k) {
            if (s[l] != ch) {
                --cnt;
            }
            ++l;
        }
        maxi = max(maxi, r - l + 1);
        ++r;
    }
    return maxi;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res = max(res, solve(s, i + 'a', k));
        }
        for (int i = 0; i < 26; ++i) {
            res = max(res, solve(s, i + 'A', k));
        }
        cout << res << endl;
    }
    return 0;
}