#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main(){

    FAST_IO;    

    ll t;
    cin >> t;

    ll n, m;
    while (t--) {
        cin >> n >> m;
        if (n % (m + 1) == 0) {
            cout << "B";
        } else {
            cout << "A";
        }
        cout << endl;
    }

    return 0;
}