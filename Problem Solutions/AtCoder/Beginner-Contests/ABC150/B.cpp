#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {

    FAST_IO;

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i <= n - 3; ++i) {
        string temp = s.substr(i, 3);
        if (temp == "ABC") {
            ++cnt;
        }
    }
    cout << cnt << endl;
    
    return 0;
}