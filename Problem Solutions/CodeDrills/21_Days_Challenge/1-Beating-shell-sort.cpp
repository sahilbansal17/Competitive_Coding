/*
 * Problem Link: https://codedrills.io/problems/day-1-beating-shell-sort
 * Concepts involved: Shell Sort
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX 5001
int main () {

    int n;
    cin >> n;

    vector<int> gaps(n);
    for (auto &gap: gaps) {
        cin >> gap;
    }

    // reverse(gaps.begin(), gaps.end());
    int res = 0;
    for (int i = 0; i < MAX; ++i) {
        int j = i;
        int cur = 0;
        while (j != 0 && cur < n) {
            while (j >= gaps[cur]) {
                j -= gaps[cur];
            }
            ++cur;
        }
        if (j != 0) {
            // cout << i << endl;
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}