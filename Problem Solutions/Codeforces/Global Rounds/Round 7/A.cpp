#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    int n;
    while (t--){
        cin >> n;

        if (n == 1) {
            cout << "-1" << endl;
        } else {
            int sum = (n - 1)*2;
            int rep = n - 1;
            if ((sum + 3) % 3 == 0) {
                rep = n - 2;
            }
            for (int i = 0; i < rep; ++i) {
                cout << 2;
            }
            if (rep == n - 2) {
                cout << 3;
            }
            cout << 3 << endl;
        }
    }
    
    return 0;
}