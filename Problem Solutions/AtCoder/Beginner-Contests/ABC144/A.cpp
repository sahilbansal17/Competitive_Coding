#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
int main() {
    FAST_IO;
    
    int a, b;
    cin >> a >> b;

    if (a <= 9 && b <= 9) {
        cout << a*b << endl;
        return 0;
    }
    cout << "-1" << endl;
    return 0;
}