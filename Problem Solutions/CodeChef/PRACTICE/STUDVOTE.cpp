#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n, 0);
        vector<int> cnt(101, 0);
        unordered_set<int> self_vote;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++cnt[x];
            if (i + 1 == x) {
                self_vote.insert(i + 1);
            }
        }
        int res = 0;
        for (int i = 1; i <= 100; ++i) {
            if (self_vote.find(i) == self_vote.end() && cnt[i] >= k) {
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}