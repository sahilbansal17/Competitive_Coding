#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;

        vector<int> x(n);
        for (auto &element: x) {
            cin >> element;
        }

        sort(x.begin(), x.end());

        int max_covered = 1;
        int max_x = x[0];
        int cur_start = 0;
        int cur_end = 0;
        int cur_covered = 0;
        while (cur_start < n) {
            while (cur_end < n && x[cur_end] - x[cur_start] <= l) {
                ++cur_end;
            }
            cur_covered = cur_end - cur_start;
            if (cur_covered >= max_covered) {
                max_covered = cur_covered;
                max_x = max(x[cur_start], x[cur_end - 1] - l);
            }
            ++cur_start;
        }
        cout << max_covered << " " << max_x << endl;
    }
    return 0;
}