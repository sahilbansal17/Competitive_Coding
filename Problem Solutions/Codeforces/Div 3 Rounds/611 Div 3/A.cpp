#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    int h, m;
    while (t--) {
        cin >> h >> m;
        int cur = h*60 + m;
        cout << 24*60 - cur << endl;
    }

    return 0;
}