#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const float PI = 3.14159;

int main() {
    FAST_IO;
    
    float a, b, x;
    cin >> a >> b >> x;

    float theta1 = atanf((2.0*(a*a*b - x))/(a*a*a));
    float theta2 = atanf((a*b*b)/(2.0*x));
    float res1 = 180.0*(theta1/PI);
    float res2 = 180.0*(theta2/PI);

    float z = b/tan(theta2);
    if (z < a) {
        cout << fixed;
        cout << setprecision(6) << res2 << endl;
    } else {
        cout << fixed;
        cout << setprecision(6) << res1 << endl;
    }
    
    return 0;
}