#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
const int MAX = 2e5 + 10;

int main() {
    FAST_IO;

    int n;
    cin >> n;

    set<int> s;
    int x;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        --x;
        if (x == i) {
            ++res;
        } else {
            s.insert(x);
        }
    }

    res += s.size()/2;
    cout << res << endl;
    return 0;
}