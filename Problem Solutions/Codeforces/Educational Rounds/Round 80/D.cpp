#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int ans_1 = 0, ans_2 = 0;
bool possible(int mid, vector<vector<int>>& a) {
    map<int, int> bitmasks;
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; ++i) {
        int res = 0;
        int pow = 1;
        for (int j = m - 1; j >= 0; --j) {
            res += pow * (a[i][j] >= mid);
            pow *= 2;
        }
        bitmasks[res] = i;
    }
    int max_val = pow(2, m) - 1;
    for (auto mask1: bitmasks) {
        for (auto mask2: bitmasks) {
            int val1 = mask1.first;
            int val2 = mask2.first;
            int id1 = mask1.second;
            int id2 = mask2.second;
            if ((val1 | val2) == max_val) {
                ans_1 = id1;
                ans_2 = id2;
                return true;
            }
        }
    }
    return false;
}

int main() {
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x: a) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    int low = 0;
    int high = 1000000001;
    int mid;
    while (abs(low - high) > 1) {
        mid = low + (high - low)/2;
        if (possible(mid, a)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << 1 + ans_1 << " " << 1 + ans_2 << endl;
    return 0;
}