#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cur = arr[0];
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == cur) {
                ++count;
            } else if (count > n/4) {
                return cur;
            } else {
                cur = arr[i];
                count = 1;
            }
        }
        return cur;
    }
};

int main () {
    Solution solver;
    vector<int> inp = {1,2,2,6,6,6,6,7,10};
    cout << solver.findSpecialInteger(inp) << endl;
    return 0;
}