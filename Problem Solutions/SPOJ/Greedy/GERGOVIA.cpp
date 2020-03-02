#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef long long ll;

int main () {

    int n;
    cin >> n;
    while (n != 0) {
        vector<ll> v(n);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (v[i] > 0) {
                pq.push({i, v[i]});
            }
        }

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] < 0) {
                while (!pq.empty() && v[i] < 0) {
                    int idx = pq.top().first;
                    ll val = pq.top().second;
                    if (val < abs(v[i])) {
                        pq.pop();
                        res += (val)*abs(idx - i);
                        v[i] += val;
                    } else if (val >= abs(v[i])) {
                        res += (abs(v[i]))*abs(idx - i);
                        pq.pop();
                        pq.push({idx, val - abs(v[i])});
                        v[i] = 0;
                    }
                }
            }
        }
        cout << res << endl;
        cin >> n;
    }
    return 0;
}