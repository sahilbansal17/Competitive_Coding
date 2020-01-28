/*
 * Problem Link: https://www.spoj.com/problems/ANARC05B/
 */
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, vector<int>& b) {
    int res = 0;
    int n = b.size();
    vector<int> prefixB(n, 0);
    prefixB[0] = b[0];
    for (int i = 1; i < n; ++i) {
        prefixB[i] = prefixB[i - 1] + b[i];
    }
    int p2 = 0;
    int s1 = 0, s2 = 0;
    n = a.size();
    for (int i = 0; i < n; ++i) {
        s1 += a[i];
        if (binary_search(b.begin() + p2, b.end(), a[i])) {
            int idx = lower_bound(b.begin() + p2, b.end(), a[i]) - b.begin();
            s2 = prefixB[idx];
            if (p2 != 0) {
                s2 -= prefixB[p2 - 1];
            }
            res += max(s1, s2);
            s1 = 0;
            s2 = 0;
            p2 = idx + 1;
        }   
    }
    s2 = prefixB[b.size() - 1];
    if (p2 != 0) {
        s2 -= prefixB[p2 - 1];
    }
    res += max(s1, s2);
    return res;
}

int main () {

    int n;
    cin >> n;
    while (n != 0) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        cin >> n;
        cout << solve(a, b) << endl;
    }
    return 0;
}