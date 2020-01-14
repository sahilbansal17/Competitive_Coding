#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {

    FAST_IO;

    int n, k, m;
    cin >> n >> k >> m;

    int req = n*m;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    int res = req - sum;
    if (res <= 0) {
        res = 0;
    }
    if (res > k) {
        cout << "-1" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}