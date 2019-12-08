#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        
        map<int, vector<int>> groups;
        int n = groupSizes.size();
        for (int i = 0; i < n; ++i) {
            int sz = groupSizes[i];
            groups[sz].push_back(i);
            if (groups[sz].size() == sz) {
                res.push_back(groups[sz]);
                groups[sz].clear();
            }
        }
        return res;
    }
};

int main() {
    Solution solver;
    vector<int> inp = {3,3,3,3,3,1,3};
    vector<vector<int>> res = solver.groupThePeople(inp);
    for (auto vi: res) {
        for (auto x: vi) {
            cout << x << " ";
        }
        cout << '\n';
    }
}