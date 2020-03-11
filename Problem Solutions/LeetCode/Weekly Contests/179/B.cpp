#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int max = 0;
        int n = light.size();
        for (int i = 0; i < n; ++i) {
            if (light[i] > max) {
                max = light[i];
            }
            if (max == i + 1) {
                ++res;
            }
        }
        return res;
    }
};
int main () {
    Solution solver;
    vector<int> lights = {1, 2, 3, 4};
    cout << solver.numTimesAllBlue(lights) << endl;
    return 0;
}