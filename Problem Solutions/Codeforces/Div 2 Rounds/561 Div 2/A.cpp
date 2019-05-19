#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main(){

    FAST_IO;
    
    int n;
    cin >> n;

    string s;
    int cnt[26] = {0};
    for (int i = 0; i < n; i ++) {
        cin >> s;
        cnt[s[0] - 'a'] ++;
    }

    int res = 0;
    for (int i = 0; i < 26; i ++) {
        if (cnt[i] % 2 == 0) {
            res += 2*((cnt[i]/2) * (cnt[i]/2 - 1))/2;
        }
        else {
            res += ((cnt[i]/2) * (cnt[i]/2 - 1))/2;
            res += ((cnt[i]/2 + 1) * (cnt[i]/2))/2;
        }
    }

    cout << res << endl;

    return 0;
}