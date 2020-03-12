#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        // jump only on R's greedy approach
        string s;
        cin >> s;

        int max_dist = 0;
        int n = s.length();
        int prev = -1;
        int cur_dist;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                cur_dist = i - prev;
                prev = i;
                max_dist = max(max_dist, cur_dist);
            }
        }
        cur_dist = n - prev;
        if (cur_dist > max_dist) {
            max_dist = cur_dist;
        }
        cout << max_dist << endl;
    }
    
    return 0;
}