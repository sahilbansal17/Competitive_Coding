#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1e9 + 7;

int main () {
    FAST_IO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    stack<int> st;
    ll res = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (st.empty()) {
            st.push(n - 1);
        } else {
            if (a[st.top()] >= a[i]) {
                while (!st.empty() && a[st.top()] >= a[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    res *= 1ll*(st.top() - i + 1);
                    res %= MOD;
                }
                st.push(i);
            } else {
                if (!st.empty()) {
                    res *= 1ll*(st.top() - i + 1);
                    res %= MOD;
                }
                st.push(i);
            }
        }
    }
    cout << res << endl;
    return 0;
}