#include <iostream>
using namespace std;

typedef long long ll;
int main() {
    int t;
    cin >> t;
    
    int x, y, a, b;
    for (int i = 0; i < t; i ++) {
        cin >> x >> y >> a >> b;
        
        ll total = 1ll*x*y;
        ll sum = a + b;
        if (total == sum) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
