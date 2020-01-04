#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;
const int MAXX = 1000010;
int main() {
    FAST_IO;

    int n;
    cin >> n;

    int l;
    bool has[MAX];
    memset(has, false, sizeof(has));
    vector<int> a(n), cnt(MAXX, 0);
    for (int j = 0; j < n; ++j) {
        cin >> l;

        int prev = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int x;
        for (int i = 0; i < l; ++i) {
            cin >> x;
            if (i == 0) {
                prev = x;
                mini = x;
                maxi = x;
            } else {
                if (x > maxi) {
                    maxi = x;
                }
                if (x < mini) {
                    mini = x;
                }
                if (prev < x) {
                    has[j] = true;
                }
            }
            prev = x;
        }
        if (!has[j]) {
            ++cnt[maxi];
        }
        a[j] = mini;   
    }

    for (int i = 1; i < MAXX; ++i) {
        cnt[i] = cnt[i - 1] + cnt[i];
    }

    ll total = 1ll*n*n;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (!has[i]) {
            // cout << a[i] << endl;
            res += 1ll*cnt[a[i]];
        }
    }
    cout << total - res << endl;
    return 0;
}