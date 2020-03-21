/*
 * References:
 * https://www.geeksforgeeks.org/make_heap-in-cpp-stl/
 * https://www.geeksforgeeks.org/heap-using-stl-c/
 */


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n - k];
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};