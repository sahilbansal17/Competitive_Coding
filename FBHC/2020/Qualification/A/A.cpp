#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
/**
 * Uncomment the #define below if problem contains multiple test cases
 */
#define MULTIPLE_TESTS 1

template <typename T>
inline void printGrid(vector<vector<T>>& grid) {
  int R = grid.size();
  if (R == 0) {
    return; // empty grid
  }
  int C = grid[0].size();
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void solve(int case_no) {
  int num_countries;
  cin >> num_countries;

  string incoming, outgoing;
  cin >> incoming >> outgoing;

  vector<vector<char>> res(num_countries, vector<char>(num_countries, '?'));
  for (int id = 0; id < num_countries; ++id) {
    res[id][id] = 'Y';
  }
  // solve for i to j where i < j
  for (int row = 0; row < num_countries; ++row) {
    for (int col = row + 1; col < num_countries; ++col) {
      // must be able to reach atleast 1 less than the current dest from the given 'row' country
      if (res[row][col - 1] == 'N') {
        res[row][col] = 'N';
      } else {
        // outgoing from src must be allowed as well incoming to the dest
        if (outgoing[col - 1] == 'Y' && incoming[col] == 'Y') {
          res[row][col] = 'Y';
        } else {
          res[row][col] = 'N';
        }
      }
    }
  }
  // solve for j to i where j < i
  for (int row = 0; row < num_countries; ++row) {
    for (int col = row - 1; col >= 0; --col) {
      // must be able to reach atleast 1 more than the current dest from the given 'row' country
      if (res[row][col + 1] == 'N') {
        res[row][col] = 'N';
      } else {
        // outgoing from src must be allowed as well incoming to the dest
        if (outgoing[col + 1] == 'Y' && incoming[col] == 'Y') {
          res[row][col] = 'Y';
        } else {
          res[row][col] = 'N';
        }
      }
    }
  }
  cout << "Case #" << case_no << ": " << endl;
  printGrid(res);
}

int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  for (int case_no = 1; case_no <= t; ++case_no) {
    solve(case_no);
  }

  return 0;
}