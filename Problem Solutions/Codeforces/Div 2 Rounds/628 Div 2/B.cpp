#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {

    FAST_IO;
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_set<int> s;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            s.insert(x);
        }

        cout << s.size() << endl;
    }
    return 0;
}