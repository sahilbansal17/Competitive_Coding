#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  // preprocessing
  vector<vector<int>> freq;
  bool feasible(int pos, string &s, string &name) {
    vector<int> freqName(26, 0);
    int len = name.length();
    for (int i = 0; i < len; ++i) {
      ++freqName[name[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (freqName[i] > freq[pos][i]) {
        return 0;
      }
    }
    return 1;
  }
 public:
  vector<int> solve(int n, int m, string s, vector<string> names) {
    vector<int> res;
    freq.assign(n, vector<int> (26, 0));
    for (int i = 0; i < n; ++i) {
      if (i != 0) {
        for (int j = 0; j < 26; ++j) {
          freq[i][j] = freq[i - 1][j];
        }
      }
      ++freq[i][s[i] - 'a'];
    }
    for (int i = 0; i < m; ++i) {
      string name = names[i];
      int len = name.length();
      int low = 0, high = n - 1;
      while (low < high) {
        int mid = low + ((high - low)>>2);
        if (feasible(mid, s, name)) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      res.push_back(1 + high);
    }
    return res;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  int n, m;
  cin >> n;
  string s;
  cin >> s;
  cin >> m;
  vector<string> names;
  string name;
  for (int i = 0; i < m; ++i) {
    cin >> name;
    names.push_back(name);
  }
  Solution solver;
  vector<int> res = solver.solve(n, m, s, names);
  for (int i = 0; i < m; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}