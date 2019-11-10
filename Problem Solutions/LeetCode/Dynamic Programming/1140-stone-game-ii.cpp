class Solution {
private:
    vector<int> prefixSum;
    int maxStones[110][100][2];
public:
    int getSum(int st, int en) {
        // sum from st to en
        int sum = prefixSum[en];
        if (st != 0) {
            sum -= prefixSum[st - 1];
        }
        return sum;
    }
    int solve(int cur, int M, int turn, int numPiles) {
        // base case
        if (cur >= numPiles) {
            return 0;
        }
        if (maxStones[cur][M][turn] != -1) {
            return maxStones[cur][M][turn];
        }
        int newT = turn ^ 1;
        if (turn == 0) {
            int res = 0;
            int end = min(numPiles, cur + 2*M);
            for (int next = cur + 1; next <= end; ++next) {
                int sum = getSum(cur, next - 1);
                int newM = max(M, next - cur); // picked next-cur elements = X
                res = max(res, sum + solve(next, newM, newT, numPiles));
            }
            maxStones[cur][M][turn] = res;
        } else {
            int res = INT_MAX;
            int end = min(numPiles, cur + 2*M);
            for (int next = cur + 1; next <= end; ++next) {
                int sum = getSum(cur, next - 1);
                int newM = max(M, next - cur);
                res = min(res, solve(next, newM, newT, numPiles));
            }
            if (res == INT_MAX) {
                res = 0;
            }
            maxStones[cur][M][turn] = res;
        }
        return maxStones[cur][M][turn];
    }
    int stoneGameII(vector<int>& piles) {
        prefixSum = piles;
        for (int i = 1; i < piles.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + piles[i];
        }
        memset(maxStones, -1, sizeof(maxStones));
        // i, M, turn, piles, maxStones
        int res = solve(0, 1, 0, piles.size());
        return res;
    }
};