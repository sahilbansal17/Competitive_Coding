int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};

template <typename T>
inline void readGrid(vector<vector<T>>& grid, int R, int C) {
  grid.assign(R, vector<T>(C));
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cin >> grid[r][c];
    }
  }
}

template <typename T>
inline void printGrid(const vector<vector<T>>& grid) {
  int R = grid.size();
  if (R == 0) {
    return;
  }
  int C = grid[0].size();
  if (C == 0) {
    return;
  }
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cout << grid[r][c] << " ";
    }
    cout << endl;
  }
}

inline bool safeChecker(int x, int y, int R, int C) {
  if (x < 0 || y < 0 || x >= R || y >= C) {
    return false;
  }
  return true;
}