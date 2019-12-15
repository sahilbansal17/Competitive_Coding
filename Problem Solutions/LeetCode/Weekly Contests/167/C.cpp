#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
 * Reference taken from: https://www.geeksforgeeks.org/submatrix-sum-queries/
 */

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        if (rows == 0) {
            return 0;
        }
        int cols = mat[0].size();
        if (cols == 0) {
            return 0;
        }
        
        vector<vector<int>> sum(rows, vector<int> (cols, 0));
        for (int i = 0; i < cols; ++i) {
            sum[0][i] = mat[0][i];
        }
        
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum[i][j] = mat[i][j] + sum[i - 1][j];
            }
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        
        int res = 0;
        for (int len = 1; len <= min(rows, cols); ++len) {
            for (int x = 0; x <= rows - len; ++x) {
                for (int y = 0; y <= cols - len; ++y) {
                    int x2 = x + len - 1;
                    int y2 = y + len - 1;
                    int cur = sum[x2][y2];
                    if (x > 0) {
                        cur -= sum[x - 1][y2];
                    }
                    if (y > 0) {
                        cur -= sum[x2][y - 1];
                    }
                    if (x > 0 && y > 0) {
                        cur += sum[x - 1][y - 1];
                    }
                    if (cur <= threshold) {
                        if (len > res) {
                            res = len;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main () {
    vector<vector<int> > inp = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    int threshold = 4;
    Solution solver;
    cout << solver.maxSideLength(inp, threshold) << endl; // 2
    return 0;
}