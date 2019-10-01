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

// w: max no. of queries
int interact(int w) {
    // return -1 if interaction resulted in failure
    return -1;
}

int calculate(int x) {
    // return the res after calculation
    return 1;
}

void display(int res) {
    // display the result
    cout << res << endl;
    cout.flush();
}

bool check() {
    int status;
    cin >> status;
    if (status == -1) {
        return 0;
    }
    return 1;
}

bool solve(int case_no, int w) {
    int interact_res;
    // interactions => solve function
    interact_res = interact(w);

    // failure
    if (interact_res == -1) {
        return 0;
    }

    // calculate result
    int res;
    // get res => calculate function
    res = calculate(interact_res);

    // output result => display function
    display(res);

    // check the result
    bool status = check(); 
    if (status == 0) {
        return 0;
    }
    return 1;
}

int main(){ 

    FAST_IO;

    int t, w;
    cin >> t >> w;

    for (int i = 0; i < t; i ++) {
        // W max queries
        int res = solve(i + 1, w);
        // break if the result is wrong
        if (res == 0) {
            break;
        }
    }

    return 0;
}