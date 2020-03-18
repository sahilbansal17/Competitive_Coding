#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

bool possible(int k, vector<int>& c, int d) {
    int steps = 0;
    int n = c.size();
    for (int i = 0; i < n; ++i) {
        steps += ceil((1.0 * c[i])/k);
        if (steps > d) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FAST_IO;
    
    int n, d;
    cin >> n >> d;

    vector<int> c(n);
    int maxi = -1;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] > maxi) {
            maxi = c[i];
        }
    }

    if (d < n) {
        cout << "-1" << endl;
    } else if (d == n) {
        cout << maxi << endl;
    } else {
        int low = 1, high = maxi;
        int mid;
        while (low < high) {
            mid = (low + (high - low)/2);
            if (possible(mid, c, d)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << endl;
    }
    return 0;
}