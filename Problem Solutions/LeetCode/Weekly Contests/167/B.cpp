#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> total;
        for (int i = 1; i < 9; ++i) {
            for (int len = 2; len <= 9; ++len) {
                int num = 0;
                if (i + len - 1 > 9) {
                    continue;
                }
                for (int j = i; j < i + len; ++j) {
                    num *= 10;
                    num += j;
                }
                total.push_back(num);
            }
        }
        vector<int> res;
        for (auto x: total) {
            if (x >= low && x <= high) {
                res.push_back(x);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main () {
    Solution solver;
    vector<int> res = solver.sequentialDigits(1000, 13000);
    for (auto x: res) {
        cout << x << endl;
    }
}