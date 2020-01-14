#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;

        int mid = n/2;
        int cnt = mid + ceil((1.0*d)/(mid + 1));
        // cout << cnt << " ";
        if (cnt <= n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}