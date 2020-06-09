int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};

template <typename T>
inline void readGrid(vector<vector<T>>& grid, int R, int C) {
  grid.assign(R, vector<T>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> grid[i][j];
    }
  }
}

inline bool safeChecker(int x, int y, int R, int C) {
  if (x < 0 || y < 0 || x >= R || y >= C) {
    return false;
  }
  return true;
}