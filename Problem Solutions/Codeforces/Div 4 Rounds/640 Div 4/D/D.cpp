#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    int i = 1, j = n - 1;
    int prev = arr[0];
    int turns = 1;
    int alice = arr[0];
    int bob = 0;
    while (i <= j) {
        int cur = 0;
        if (turns & 1) {
            while (i <= j && cur <= prev) {
                cur += arr[j--];
            }
            bob += cur;
        } else {
            while (i <= j && cur <= prev) {
                cur += arr[i++];
            }
            alice += cur;
        }
        prev = cur;
        ++turns;
    }
    cout << turns << " " << alice << " " << bob << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}