/*
 * Problem Link: https://codeforces.com/contest/1250/problem/H
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    vector<pair<int, int> > candles;
    int c;
    for (int i = 0; i < 10; ++i) {
        cin >> c;
        candles.push_back(make_pair(c, i));
    }
    sort(candles.begin(), candles.end());

    string res;
    if (candles[0].second == 0) {
        if (candles[0].first == candles[1].first) {
            for (int i = 0; i <= candles[1].first; ++i) {
                res += to_string(candles[1].second);
            }
        } else {
            res += '1';
            for (int i = 0; i <= candles[0].first; ++i) {
                res += '0';
            }
        }
    } else {
        for (int i = 0; i <= candles[0].first; ++i) {
            res += to_string(candles[0].second);
        }
    }
    cout << res << endl;
}
int main() {
    FAST_IO;
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}