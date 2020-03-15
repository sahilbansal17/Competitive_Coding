/*
 * Problem Link: https://www.codechef.com/problems/PS103
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

int main() {

    FAST_IO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int minCost[n][3];
        int costs[3];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> costs[j];
            }
            if (i == 0) {
                for (int j = 0; j < 3; ++j) {
                    minCost[i][j] = costs[j];
                }
            } else {
                minCost[i][0] = costs[0] + min(minCost[i - 1][1], minCost[i - 1][2]);
                minCost[i][1] = costs[1] + min(minCost[i - 1][0], minCost[i - 1][2]);
                minCost[i][2] = costs[2] + min(minCost[i - 1][1], minCost[i - 1][0]);
            }
        }

        int res = minCost[n - 1][0];
        for (int i = 0; i < 3; ++i) {
            res = min(res, minCost[n - 1][i]);
        }
        cout << res << endl;
    }
    return 0;
}