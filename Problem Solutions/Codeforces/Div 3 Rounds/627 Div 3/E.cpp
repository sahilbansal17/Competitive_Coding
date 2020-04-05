#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 2010;
int maxGood[MAX][MAX];
int solve(int idx, int cur_hour, int hours, int left, int right, 
            vector<int>& times) {
    if (idx == times.size()) {
        if (cur_hour >= left && cur_hour <= right) {
            return 1;
        }
        return 0;
    }
    if (maxGood[idx][cur_hour] != -1) {
        return maxGood[idx][cur_hour];
    }
    int res = 0;
    if (idx != 0 && (cur_hour >= left && cur_hour <= right)) {
        res = 1;
    }
    res += max(solve(idx + 1, (cur_hour + times[idx] + hours)%hours, hours, left, right, times), 
                solve(idx + 1, (cur_hour + times[idx] - 1 + hours)%hours, hours, left, right, times));

    return maxGood[idx][cur_hour] = res;
}

int main() {
    FAST_IO;

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> st(n);
    for (auto &x: st) {
        cin >> x;
    }

    memset(maxGood, -1, sizeof(maxGood));
    cout << solve(0, 0, h, l, r, st) << endl;

    return 0;
}