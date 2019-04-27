#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

int main(){

    FAST_IO;    

    int n;
    cin >> n;

    int a[n];
    int done[101] = {0};

    vector <int> num;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (!done[a[i]]) {
            done[a[i]] = 1;
            num.push_back(a[i]);
        }
    }

    sort(num.begin(), num.end());
    int res = 0;
    int nn = num.size();
    if (nn >= 4) {
        res = -1;
    }
    else if (nn == 3) {
        if ((2*num[1]) == (num[0] + num[2])) {
            res = num[1] - num[0];
        }
        else {
            res = -1;
        }
    }
    else if (nn == 2) {
        res = num[1] - num[0];
        if (res % 2 == 0) {
            res = res/2;
        }
    }
    else if (nn == 1) {
        res = 0;
    }

    cout << res << endl;
    return 0;
}