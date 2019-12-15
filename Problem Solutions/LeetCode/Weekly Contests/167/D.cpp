/*
 * Gives memory limit exceeded
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int solve(int x, int y, int k, vector<vector<int>>& grid, vector<vector<int>>& steps, vector<vector<int>> &visited) {
        // cout << x << " " << y << " : " << k << endl; 
        if (x < 0 || y < 0 || k < 0) {
            return -1;
        }
        if (x >= grid.size() || y >= grid[0].size()) {
            return -1;
        }
        if (x == 0 && y == 0) {
            return steps[x][y] = 0;
        }
        if (steps[x][y] != -1) {
            return steps[x][y];
        }
        if (grid[x][y] == 1 && k == 0) {
            return -1;
        }
        
        vector<int> poss;
        int kp;
        if (grid[x][y] == 1) {
            kp = k - 1;
        } else {
            kp = k;
        }
        
        if ((x - 1 >= 0 && !visited[x-1][y])) {
            visited[x-1][y] = 1;
            poss.push_back(solve(x - 1, y, kp, grid, steps, visited));
            visited[x-1][y] = 0;
        }

        if ((y - 1 >= 0 && !visited[x][y-1] && steps[x][y-1] == -1)) {
            visited[x][y-1] = 1;
            poss.push_back(solve(x, y - 1, kp, grid, steps, visited));
            visited[x][y-1] = 0;
        }

        if (!visited[x+1][y] && steps[x+1][y] == -1) {
            visited[x+1][y] = 1;
            poss.push_back(solve(x + 1, y, kp, grid, steps, visited));
            visited[x+1][y] = 0;
        }

        if (!visited[x][y+1] && steps[x][y+1] == -1) {
            visited[x][y+1] = 1;
            poss.push_back(solve(x, y + 1, kp, grid, steps, visited));
            visited[x][y+1] = 0;
        }
        
        
        int cur = INT_MAX;
        bool possible = false;
        for (auto val: poss) {
            if (val < cur && val != -1) {
                cur = min(cur, 1 + val);
                possible = true;
            }
        }
        if (!possible) {
            return steps[x][y] = -1;
        }
        return steps[x][y] = cur;
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> minSteps(r + 10, vector<int> (c + 10, -1));
        vector<vector<int>> visited(r + 10, vector<int> (c + 10, 0));
        visited[r-1][c-1] = 1;
        return solve(r - 1, c - 1, k, grid, minSteps, visited);
    }
};

int main () {
    vector<vector<int> > grid = {{0,0,0},
                                 {1,1,0},
                                 {0,0,0},
                                 {0,1,1},
                                 {0,0,0}};
    int k = 1;
    Solution solver;
    cout << solver.shortestPath(grid, k) << endl; // 6 
}