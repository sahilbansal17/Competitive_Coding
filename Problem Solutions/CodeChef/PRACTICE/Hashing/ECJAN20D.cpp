#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main () {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        stack<int> st;
        unordered_set<int> seen;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (seen.find(x) == seen.end()) {
                st.push(x);
                seen.insert(x);
            }
        }
        int query;
        int l, r;
        for (int i = 0; i < q; ++i) {
            cin >> query;
            if (query == 1) {
                cin >> l;
                for (int j = 0; j < l; ++j) {
                    cin >> x;
                    if (seen.find(x) == seen.end()) {
                        st.push(x);
                        seen.insert(x);
                    }
                }
            } else {
                cin >> r;
                for (int i = 0; i < r; ++i) {
                    if (st.empty()) {
                        break;
                    }
                    x = st.top();
                    st.pop();
                    seen.erase(x);
                }
            }
        }
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}