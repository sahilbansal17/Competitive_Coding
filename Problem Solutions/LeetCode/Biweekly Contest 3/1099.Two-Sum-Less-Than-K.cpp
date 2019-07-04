class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int n = A.size();
        int bestSum = -1;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int currentSum = A[i] + A[j];
                if (currentSum > bestSum && currentSum < K) {
                    bestSum = currentSum;
                }
            }
        }
        return bestSum;
    }
};