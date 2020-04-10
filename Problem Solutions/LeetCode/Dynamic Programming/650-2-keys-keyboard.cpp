class Solution {
private:
    int steps[1010][1010];    
public:
    int solve(int cur_len, int copy_len, int N) {
        if (cur_len == N) {
            return 0;
        }
        if (cur_len > N) {
            return -1;
        }
        if (steps[cur_len][copy_len] != -1) {
            return steps[cur_len][copy_len];
        }
        int res = INT_MAX;
        // copy if copy_len != cur_len
        if (copy_len != cur_len) {
            int next = solve(cur_len, cur_len, N);
            if (next != -1) {
                res = 1 + next;
            }
        }
        // paste if copy_len > 0
        if (copy_len > 0) {
            int next = solve(cur_len + copy_len, copy_len, N);
            if (next != -1) {
                res = min(res, 1 + next);
            }
        }
        if (res == INT_MAX) {
            res = -1;
        }
        return steps[cur_len][copy_len] = res;
    }
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        memset(steps, -1, sizeof(steps));
        return solve(1, 0, n);
    }
};