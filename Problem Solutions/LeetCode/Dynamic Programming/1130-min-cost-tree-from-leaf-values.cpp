class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int minCost[n][n];
        int maxi[n][n];
        // initialize
        memset(maxi, 0, sizeof(maxi));
        memset(minCost, 0, sizeof(minCost));
        // precompute maximum values for all ranges
        for (int start = 0; start < n; ++start) {
            int curMax = arr[start];
            for (int end = start; end < n; ++end) {
                curMax = max(curMax, arr[end]);
                maxi[start][end] = curMax;
            }
        }
        // length 1
        for (int i = 0; i < n; ++i) {
            minCost[i][i] = arr[i];
        }
        // length 2
        for (int i = 0; i < n - 1; ++i) {
            minCost[i][i + 1] = arr[i] * arr[i + 1];
        }
        // length 3 onwards
        for (int len = 3; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                int minCurCost = INT_MAX;
                int curCost;
                for (int k = start; k <= end - 1; ++k) {
                    curCost = maxi[start][k] * maxi[k + 1][end];
                    if (start != k) {
                        curCost += minCost[start][k];
                    }
                    if (end != k + 1) {
                        curCost += minCost[k + 1][end];
                    }
                    minCurCost = min(minCurCost, curCost);
                }
                minCost[start][end] = minCurCost;
            }
        }
        return minCost[0][n - 1];
    }
};