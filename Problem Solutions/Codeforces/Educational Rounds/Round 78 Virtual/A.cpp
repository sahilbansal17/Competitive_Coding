#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    string pass, hash, pass_sorted;
    while (t--) {
        cin >> pass;
        cin >> hash;

        int pass_len = pass.length();
        int hash_len = hash.length();

        pass_sorted = pass;
        sort(pass_sorted.begin(), pass_sorted.end());

        if (hash_len < pass_len) {
            cout << "NO" << endl;
            continue;
        }

        bool possible = false;
        for (int start = 0; start < hash_len - pass_len + 1; ++start) {
            string cur = hash.substr(start, pass_len);
            sort(cur.begin(), cur.end());
            if (cur == pass_sorted) {
                possible = true;
                break;
            }
        }
        possible == true ? cout << "YES\n" : cout << "NO\n" ;
    }
    return 0;
}