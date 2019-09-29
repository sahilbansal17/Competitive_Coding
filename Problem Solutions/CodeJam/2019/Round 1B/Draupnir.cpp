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
vector <ll> interact(int w) {
    // return -1 if interaction resulted in failure
    vector <ll> b(6, 0);
    bool res = true;;
    for (int i = 0; i < 6; i ++) {
        cout << i + 1 << endl;
        cout.flush();
        cin >> b[i];
        if (b[i] == -1) {
            res = false;
            break;
        }
    }
    if (res == false) {
        // return empty vector
        vector <ll> temp;
        return temp;
    }
    return b;
}

vector <ll> calculate(vector <ll> b) {
    // return the res after calculation
    vector <ll> x(6, 0);

    x[0] = 4*(b[0] - b[1]) - 2*b[2] + b[5];
    x[0] /= 40;
    x[1] = 24*(b[1] - b[0]) + 2*b[2] - b[5];
    x[1] /= 20;
    x[2] = -4*b[0] -6*b[1] + 12*b[2] - b[5];
    x[2] /= 10;
    x[3] = 16*(b[0] - b[1]) - 8*b[2] + 10*b[3] - b[5];
    x[3] /= 10;
    x[4] = 8*(b[1] - b[0]) + 4*b[2] - 5*b[3] + 5*b[4] - 2*b[5];
    x[4] /= 5; 
    x[5] = 12*b[0] - 2*b[1] - 6*b[2] - 5*b[4] + 3*b[5];
    x[5] /= 5;

    return x;
}

void display(vector <ll> x) {
    for (int j = 0; j < 6; j ++) {
        cout << x[j] << " ";
    }
    cout << endl;
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
    vector <ll> interact_res;
    // interactions => solve function
    interact_res = interact(w);

    // failure
    if (interact_res.size() == 0) {
        return 0;
    }

    // calculate result
    vector <ll> res;
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
        bool res = solve(i + 1, w);
        // break if the result is wrong
        if (res == 0) {
            break;
        }
    }

    return 0;
}