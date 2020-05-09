#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
        
    int p, sum_profits = 0, sum_weights = 0;
    vector<int> W(n + 1), P(n + 1);
    for (int i = 1; i <= n; ++i) {
        // make query such that all weights from 1 to i can be selected
        cout << 1 << " " << i << " 10000" << endl;
        cout.flush();
        cin >> p;

        P[i] = p - sum_profits;
        sum_profits = p;

        // find weight of current item using binary search
        int low = 1, high = 10000;
        int mid;
        while (low < high) {
            mid = low + (high - low)/2;
            cout << 1 << " " << i << " " << mid << endl;
            cout.flush();
            cin >> p;
            if (p == sum_profits) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        W[i] = low - sum_weights;
        sum_weights = low;
    }
    cout << 2 << endl;
    for (int i = 1; i <= n; ++i) {
        cout << W[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        cout << P[i] << " ";
    }
    cout << endl;
    cout.flush();
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}