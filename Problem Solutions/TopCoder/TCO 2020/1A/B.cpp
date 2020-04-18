#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

class ThreeNeighbors {
public:
    vector <string> construct(int N) {
        vector<char> row;
        vector<string> res;
        if (N <= 48) {
            for (int i = 0; i < N + 2; ++i) {
                row.push_back('.');
            }
            string cur(row.begin(), row.end());
            res.push_back(cur);
            row.clear();
            for (int i = 0; i < N + 2; ++i) {
                row.push_back('X');
            }
            string cur2(row.begin(), row.end());
            res.push_back(cur2);
            row.clear();
            return res;
        } else {
            int rows = N/48;
            for (int i = 0; i < 50; ++i) {
                row.push_back('.');
            }
            string cur(row.begin(), row.end());
            res.push_back(cur);
            row.clear();
            for (int i = 0; i < 50; ++i) {
                row.push_back('X');
            }
            string cur2(row.begin(), row.end());
            res.push_back(cur2);
            
            row.clear();
            for (int i = 0; i < rows - 1; ++i) {
                res.push_back(cur2);
                res.push_back(cur);
                res.push_back(cur2);
            }

            int remain = N - rows*48;

            vector<vector<char>> remaining(remain + 1, vector<char>(50, 'X'));
            for (int i = 0; i < remain + 1; ++i) {
                remaining[i][0] = '.';
                if (i == remain) {
                    remaining[i][49] = '.';
                }
                string cur3(remaining[i].begin(), remaining[i].end());
                res.push_back(cur3);
            }
            return res;
        }
        return {};
    }
};

int main () {
    ThreeNeighbors e;
    vector<string> res = e.construct(50);
    for (auto s: res) {
        cout << s << endl;
    }
    cout << res.size() << endl;
    cout << res[0].size() << endl;
    return 0;
}