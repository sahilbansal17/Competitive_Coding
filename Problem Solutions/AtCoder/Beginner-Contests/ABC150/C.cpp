#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int fact[10];

bool same(vector<int> a, vector<int> b) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    FAST_IO;

    int n;
    cin >> n;

    vector<int> a(n), f(n), s(n);

    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = (i + 1);
    }

    fact[0] = 1;
    for (int i = 1; i < 10; ++i) {
        fact[i] = i*fact[i - 1];
    }

    int r1, r2;
    for (int i = 0; i < fact[n]; ++i) {
        if (same(a, f)) {
            r1 = i + 1;
        }
        if (same(a, s)) {
            r2 = i + 1;
        }
        next_permutation(a.begin(), a.end());
    }
    
    cout << abs(r1 - r2) << endl;
    return 0;
}