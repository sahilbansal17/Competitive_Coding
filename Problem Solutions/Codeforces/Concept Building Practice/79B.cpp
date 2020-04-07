#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

vector<int> blocked;
int n, m;
int query(int a, int b) {
    int x = (a - 1)*m + b;
    if (binary_search(blocked.begin(), blocked.end(), x)) {
        return 0;
    }
    // count no. of blocked cells before query cell
    int id = lower_bound(blocked.begin(), blocked.end(), x) - blocked.begin();
    int res = (x - id) % 3;
    if (res == 0) {
        res = 3;
    }
    return res;
}
int main() {
    FAST_IO;

    int k, t;
    cin >> n >> m >> k >> t;

    int a, b;
    int x;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        x = (a - 1)*m + b;
        blocked.push_back(x);
    }
    sort(blocked.begin(), blocked.end());

    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        int res = query(a, b);
        switch(res) {
            case 0: 
                cout << "Waste" << endl;
                break;
            case 1:
                cout << "Carrots" << endl;
                break;
            case 2:
                cout << "Kiwis" << endl;
                break;
            case 3:
                cout << "Grapes" << endl;
                break;
        }
    }
    
    return 0;
}