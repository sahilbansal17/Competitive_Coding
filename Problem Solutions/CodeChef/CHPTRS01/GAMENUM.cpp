#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;

void right_circular_shift(vector<int>& a) {
    int n = a.size();
    int temp = a[n - 1];
    /*            t
     *            e
     *            m
     *            p
     *            |
     *            v
     * 
     *  1    0     1
     *   \     \
     *    \     \
     *     \     \
     *      \     \
     *  1     1     0 
     * 
     *  ^
     *  |
     *  t
     *  e
     *  m
     *  p
     * 
     */

    for (int i = n - 1; i >= 1; --i) {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}

void print_bits(int n, vector<vector<int>> &bits) {
    cout << "PRINTING THE BINARY REPRESENTATIONS OF THE INPUT NUMBERS:\n";
    int c = bits[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << bits[i][j];
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------\n";
}
ll custom_xor(vector<int>& a, vector<int>& b) {
    int n = a.size();
    ll pow2 = 1;
    ll res = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            res += pow2;
        }
        pow2 *= 2;
    }
    return res;
}
void solve() {
    ll a[2];
    cin >> a[0] >> a[1];

    int c1 = log2(a[0]) + 1;
    int c2 = log2(a[1]) + 1;
    int c = max(c1, c2);

    vector<vector<int>> bits(2, vector<int> (c, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = c - 1; j >= 0; --j) { // LSB at 0th index, MSB at (c-1)
            if (a[i] & (1ll << (c - j - 1))) {
                bits[i][j] = 1;
            }
        }
    }

    ll res_max = custom_xor(bits[0], bits[1]);
    int steps = 0;
    // print_bits(2, bits);
    for (int shift = 1; shift <= c; ++shift) {
        right_circular_shift(bits[1]);
        ll cur_res = custom_xor(bits[0], bits[1]);
        // print_bits(2, bits);
        if (cur_res > res_max) {
            res_max = cur_res;
            steps = shift;
        }
    }
    cout << steps << " " << res_max << endl;
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