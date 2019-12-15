#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    unordered_map<int, string> mp;
    mp[0] = "FILIPINO";
    mp[1] = "JAPANESE";
    mp[2] = "KOREAN";
    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        if (n >= 2 && s[n - 1] == 'o' && s[n - 2] == 'p') {
            cout << mp[0] << endl;
            continue;
        } else if (n >= 4 && s[n - 1] == 'u' && s[n - 2] == 's' && s[n - 3] == 'e' && s[n - 4] == 'd') {
            cout << mp[1] << endl;
            continue;
        }  else if (n >= 4 && s[n - 1] == 'u' && s[n - 2] == 's' && s[n - 3] == 'a' && s[n - 4] == 'm') {
            cout << mp[1] << endl;
            continue;
        } else {
            cout << mp[2] << endl;
            continue;
        }
    } 

    return 0;
}