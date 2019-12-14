#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int> > &A) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int> > minSum(rows, vector<int> (cols, 0));
        // set for first row
        for (int curCol = 0; curCol < cols; ++curCol) {
            minSum[0][curCol] = A[0][curCol];
        }
        for (int curRow = 1; curRow < rows; ++curRow) {
            for (int curCol = 0; curCol < cols; ++curCol) {
                int curMinSum = INT_MAX;
                int prevRow = curRow - 1;
                for (int k = 0; k < cols; ++k) {
                    if (k == curCol) { // k = prevCol
                        continue;
                    }
                    curMinSum = min(curMinSum, minSum[prevRow][k]);
                }
                minSum[curRow][curCol] = A[curRow][curCol] + curMinSum;
            }
        }
        // result is the minimum value in the last row
        int res = INT_MAX;
        for (int curCol = 0; curCol < cols; ++curCol) {
            res = min(res, minSum[rows - 1][curCol]);
        }
        return res;
    }
};

int main () {
    vector<vector<int> > inp = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solver;
    cout << solver.minFallingPathSum(inp) << endl;
    return 0;
}