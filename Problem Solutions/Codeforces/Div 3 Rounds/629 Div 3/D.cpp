#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> t(n);
        int prev, cur;
        cin >> prev;
        t[0] = prev;
        bool all_same = true;
        for (int i = 1; i < n; ++i) {
            cin >> cur;
            t[i] = cur;
            if (cur != prev) {
                all_same = false;
            }
        }

        if (all_same) {
            cout << 1 << endl;
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << endl;
        } else {
            if (n & 1) {
                int pos = -1;
                for (int i = 0; i < n; ++i) {
                    if (t[i] == t[(i + 1) % n]) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    cout << 3 << endl;
                    int prev = 1;
                    for (int i = 0; i < n; ++i) {
                        if (i == n - 1 && (n % 3 == 1)) {
                            prev = (prev + 1) % 4;
                            if (prev == 0) {
                                prev = 1;
                            }
                        }
                        cout << prev << " ";
                        prev = (prev + 1) % 4;
                        if (prev == 0) {
                            prev = 1;
                        }
                    }
                    cout << endl;
                } else {
                    cout << 2 << endl;
                    int prev = 1;
                    for (int i = 0; i < n; ++i) {
                        cout << prev << " ";
                        if (i != pos) {
                            if (prev == 1) {
                                prev = 2;
                            } else {
                                prev = 1;
                            }
                        }
                    }
                    cout << endl;
                }
            } else {
                cout << 2 << endl;
                for (int i = 0; i < n; ++i) {
                    if (i & 1) {
                        cout << 1 << " ";
                    } else {
                        cout << 2 << " ";
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}