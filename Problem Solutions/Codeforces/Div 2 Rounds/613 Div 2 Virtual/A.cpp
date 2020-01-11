#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n;
    cin >> n;

    int c1 = 0, c2 = 0;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            --c1;
        } else {
            ++c2;
        }
    }
    cout << c2 - c1 + 1 << endl;

    return 0;
}