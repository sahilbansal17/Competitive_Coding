#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

// https://codeforces.com/blog/entry/12274
// https://stackoverflow.com/questions/17010914/algorithm-for-maximum-non-dominated-set
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/524039/C-solution-(O(nlog(n))-fast-100)
int main(){

    FAST_IO;    

    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<ll, ll>> pts;
        ll x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            pts.push_back({x, y});
        }
        sort(pts.begin(), pts.end());

        vector<int> nums(n), arr(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = pts[i].second;
        }
        int LIS = 0;
        arr[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > arr[LIS]) {
                arr[LIS + 1] = nums[i];
                ++LIS;
            } else {
                for (int j = 0; j <= LIS; ++j) {
                    if (arr[j] >= nums[i]) {
                        arr[j] = nums[i];
                        break;
                    }
                }
            }
        }
        cout << LIS + 1 << endl;
    }

    return 0;
}