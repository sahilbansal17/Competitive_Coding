#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

class EllysAndXor {
public:
    int getMax(vector<int> numbers) {
        int res = 0;
        int n = numbers.size();
        queue<int> cur;
        cur.push(numbers[0]);
        for (int i = 1; i < n; ++i) {
            int k = cur.size();
            for (int j = 0; j < k; ++j) {
                int t = cur.front();
                cur.pop();
                cur.push(t ^ numbers[i]);
                cur.push(t & numbers[i]);
            }
        }
        while (!cur.empty()) {
            int t = cur.front();
            cur.pop();
            if (t > res) {
                res = t;
            }
        }
        return res;
    }
};

int main () {
    EllysAndXor e;
    cout << e.getMax({42, 27, 38}) << endl;
    return 0;
}