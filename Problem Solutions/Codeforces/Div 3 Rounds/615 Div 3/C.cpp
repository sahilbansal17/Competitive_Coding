#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    ll n;
    while (t--) {
        cin >> n;

        int p = sqrt(n);
        int copy = n;
        vector<int> facs;
        unordered_map<int, int> cnt;
        for (int i = 2; i <= p; ++i) {
            int ct = 0;
            while (n % i == 0) {
                n /= i;
                ++ct;
            }
            if (ct != 0) {
                facs.push_back(i);
                cnt[i] = ct;
            }
        }
        if (n != 1) {
            facs.push_back(n);
            cnt[n] = 1;
        }

        int sz = facs.size();
        int val;
        if (sz == 1) {
            val = facs[0];
            if (cnt[val] < 6) {
                cout << "NO" << endl;
            } else {
                int a = val;
                int b = val*val;
                int c = 1;
                for (int i = 0; i < cnt[val] - 3; ++i) {
                    c *= val;
                }
                cout << "YES" << endl;
                cout << a << " " << b << " " << c << endl;
            }
        } else if (sz == 2) {
            int a = facs[0];
            int b = facs[1];
            int c = 1;
            for (int j = 0; j <= 1; ++j) {
                for (int i = 0; i < cnt[facs[j]] - 1; ++i) {
                    c *= facs[j];
                }
            }
            if (c == 1 || c == a || c == b) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                cout << a << " " << b << " " << c << endl;
            }
        } else {
            int a = facs[0];
            int b = facs[1];
            int c = (copy)/(a*b);
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}