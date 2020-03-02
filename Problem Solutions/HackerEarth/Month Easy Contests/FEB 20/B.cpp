#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MOD = 1e9 + 7;
int main() {
    FAST_IO;

    int n, k;
    cin >> n >> k;

    deque<ll> dq;
    ll sum = 1;
    dq.push_front(1);
    for (int i = 1; i < n - 1; ++i) {
        if (dq.size() == k) {
            dq.push_back(sum);
            sum += sum;
            sum %= MOD;
            sum -= dq.front();
            sum += MOD;
            sum %= MOD;
            dq.pop_front();
        } else {
            dq.push_back(sum);
            sum += sum;
            sum %= MOD;
        }
    }
    cout << sum << endl;
    return 0;
}