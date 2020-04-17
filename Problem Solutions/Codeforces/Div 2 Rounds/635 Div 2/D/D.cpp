#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

ll subproblem_solve(vector<ll>& left, vector<ll> &middle, vector<ll>& right) {
    ll res = LLONG_MAX;
    int l = left.size();
    int r = right.size();
    for (auto mid: middle) {
        ll lt = lower_bound(left.begin(), left.end(), mid) - left.begin();
        if (lt == l || (left[lt] > mid && lt >= 1)) {
            lt = left[lt - 1];
        } else if (lt == l) {
            continue;
        } else {
            lt = left[lt];
        }
        ll rt = upper_bound(right.begin(), right.end(), mid) - right.begin();
        if (rt - 1 >= 0 && right[rt - 1] >= mid) {
            rt = right[rt - 1];
        } else if (rt == r) {
            continue;
        } else {
            rt = right[rt];
        }
        res = min(res, abs(lt-mid)*abs(lt-mid) + abs(lt-rt)*abs(lt-rt) + abs(rt-mid)*abs(rt-mid));
    }
    return res;
}
void solve() {
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;

    vector<ll> A(n1), B(n2), C(n3);
    for (auto &x: A) {
        cin >> x;
    }
    for (auto &x: B) {
        cin >> x;
    }
    for (auto &x: C) {
        cin >> x;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    ll res = LLONG_MAX;
    res = min(res, subproblem_solve(A, B, C));
    res = min(res, subproblem_solve(A, C, B));
    res = min(res, subproblem_solve(B, C, A));
    res = min(res, subproblem_solve(B, A, C));
    res = min(res, subproblem_solve(C, B, A));
    res = min(res, subproblem_solve(C, A, B));
    cout << res << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}