#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doOverlap(vector<int> it1, vector<int> it2) {
        return (it2[0] <= it1[0] && it1[1] <= it2[1]) || (it1[0] <= it2[0] && it2[1] <= it1[1]);
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > res;
        int n = intervals.size();
        if (n == 0) {
            return {};
        }
        vector<int> cur = intervals[0];
        for (auto next: vector<vector<int> > (intervals.begin() + 1, intervals.end())) {
            // cout << next[0] << " ";
            if (!doOverlap(cur, next)) {
                res.push_back(cur);
                cur = next;
            } else {
                cur[1] = max(cur[1], next[1]);
            }
        }
        res.push_back(cur);
        return res.size();
    }
};

int main () {
    Solution solver;
    vector<vector<int> > inp = {{1, 4}, {3, 6}, {2, 8}};
    cout << solver.removeCoveredIntervals(inp) << endl;
    return 0;
}