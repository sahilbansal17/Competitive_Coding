#include <iostream>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template<typename T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

template<typename T>
T power(T x, T y, ll m = MOD) {
  T ans = 1;
  x %= m;
  while (y > 0) {
    if (y & 1LL) {
      ans = (ans * x) % m;
    }
    y >>= 1LL;
    x = (x * x) % m;
  }
  return (ans % m);
}

class BPlusFromPicture {
 private:
  char mat[510][510];
  char done[510][510];
  int h, w;
 public:
  bool check(int i, int j) {
    int dx[4] = {-1, 0, 0, +1};
    int dy[4] = {0, -1, +1, 0};
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && x < h && y >= 0 && y < w) {
        if (mat[x][y] == '*') {
          cnt++;
        }
      }
    }
    if (cnt == 4) {
      return 1;
    }
    return 0;
  }

  void markDone(int i, int j) {
    for (int l = i - 1; l >= 0; l--) {
      if (mat[l][j] == '*') {
        done[l][j] = 1;
      } else {
        break;
      }
    }
    for (int l = i + 1; l < h; l++) {
      if (mat[l][j] == '*') {
        done[l][j] = 1;
      } else {
        break;
      }
    }
    for (int m = j - 1; m >= 0; m--) {
      if (mat[i][m] == '*') {
        done[i][m] = 1;
      } else {
        break;
      }
    }
    for (int m = j + 1; m < w; m++) {
      if (mat[i][m] == '*') {
        done[i][m] = 1;
      } else {
        break;
      }
    }
  }
  void solve(std::istream &cin, std::ostream &cout) {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> mat[i][j];
      }
    }

    int cnt = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mat[i][j] == '*') {
          if (!done[i][j]) {
            if (check(i, j)) {
              cnt++;
              done[i][j] = 1;
              markDone(i, j);
            }
          }
        }
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mat[i][j] == '*' && !done[i][j]) {
          cout << "NO" << endl;
          return;
        }
      }
    }
    if (cnt == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
};

int main() {

  FAST_IO;

  BPlusFromPicture solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);

  return 0;
}