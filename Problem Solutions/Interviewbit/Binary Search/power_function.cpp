#include <iostream>
using namespace std;
typedef long long ll;

class Solution {
    public:
    int pow(int x, int n, int d);
};

int Solution::pow(int x, int n, int d) {
    ll res = 1;
    ll xx = 1ll*x;
    while (n) {
        if (n & 1) {
            res *= xx;
            res %= d;
        }
        xx *= xx;
        xx %= d;
        n >>= 1;
    }
    res = (res + d) % d;
    return (int)res;
}

int main() {
    int x = 3;
    int n = 5;
    int d = 10000000007;
    Solution solver;
    cout << solver.pow(x, n, d) << endl; // 243
}