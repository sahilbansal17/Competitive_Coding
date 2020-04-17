/**
 * Explanation: https://github.com/MathProgrammer/CodeForces/blob/master/2020/Div%202/632%20Div%202/Explanations/Kate%20and%20Imperfection%20Explanation.txt
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(int n) {
    vector<int> largest_divisor(n + 1, 1);
    for (int i = 2; i <= n/2; ++i) {
        for (int j = i*2; j <= n; j += i) {
            largest_divisor[j] = i;
        }
    }

    sort(largest_divisor.begin(), largest_divisor.end());
    for (int i = 2; i <= n; ++i) {
        cout << largest_divisor[i] << " ";
    }
    cout << endl;
}

int main() {
    FAST_IO;

    int n;
    cin >> n;

    solve(n);

    return 0;
}