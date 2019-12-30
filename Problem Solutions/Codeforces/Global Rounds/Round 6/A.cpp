#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int l = s.length();
        int sum = 0, count0 = 0, count5 = 0;
        int dig;
        for (int i = 0; i < l; ++i) {
            dig = (s[i] - '0');
            sum += dig;
            if (dig == 0) {
                ++count0;
            } else if (dig == 5) {
                ++count5;
            }
        }

        if (sum % 3 != 0) {
            cout << "cyan" << endl;
            continue;
        }
        if (count0 == 0) {
            cout << "cyan" << endl;
            continue;
        }

        int div4 = 0;
        int dig1, dig2;
        bool possible = false;
        for (int first = 0; first < l; ++first) {
            for (int second = 0; second < l; ++second) {
                if (first == second) {
                    continue;
                }
                dig1 = s[first] - '0';
                dig2 = s[second] - '0';
                if (dig1 != 0) {
                    continue;
                }
                if ((dig2 * 10 + dig1) % 4 == 0) {
                    possible = true;
                }
            }
        }
        if (possible) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }    

    return 0;
}