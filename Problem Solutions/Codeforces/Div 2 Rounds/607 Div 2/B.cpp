#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        string s, c;
        cin >> s >> c;

        int n = s.length();
        int m = c.length();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i]-'A'];
        }
        
        for (int i = 0; i < min(n, m); ++i) {
            --cnt[s[i] - 'A'];
            if (s[i] < c[i]) {
                break;
            } else if (s[i] == c[i]) {
                // see if we can get a better character
                bool done = false;
                for (int j = 0; j <= c[i] - 'A' - 1; ++j) {
                    if (cnt[j] > 0) {
                        char y = ('A' + j);
                        char t = s[i];
                        s[i] = y;
                        // need to do in the reverse direction!!!
                        for (int k = n - 1; k > i; --k) {
                            if (s[k] == y) {
                                s[k] = t;
                                break;
                            }
                        }
                        done = true;
                        break;
                    }
                }
                if (done) {
                    break;
                }
                // otherwise continue with the same char
            } else {
                // s[i] > c[i]
                bool done = false;
                // see if we can get a better char
                for (int j = 0; j <= c[i] - 'A'; ++j) {
                    if (cnt[j] > 0) {
                        char y = ('A' + j);
                        char t = s[i];
                        s[i] = y;
                        for (int k = n - 1; k > i; --k) {
                            if (s[k] == y) {
                                s[k] = t;
                                break;
                            }
                        }
                        done = true;
                        break;
                    }
                }
                // either we did swap or are unsuccessful
                break;
            }
        }
        // cout << s << " : ";
        
        bool done = false;
        if (s < c) {
            cout << s << endl;
        } else {
            cout << "---" << endl;
        }
    }
    return 0;
}