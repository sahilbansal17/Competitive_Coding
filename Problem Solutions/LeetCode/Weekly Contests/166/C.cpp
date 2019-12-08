#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool possible(int mid, int threshold, vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += ceil((1.0*num)/mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxNum = nums[0];
        for (auto num: nums) {
            if (num > maxNum) {
                maxNum = num;
            }
        }
        int low = 1, high = maxNum;
        int mid;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            if (possible(mid, threshold, nums)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2,3,5,7,11};
    int threshold = 11;
    cout << solver.smallestDivisor(nums, threshold) << '\n';
    return 0;
}