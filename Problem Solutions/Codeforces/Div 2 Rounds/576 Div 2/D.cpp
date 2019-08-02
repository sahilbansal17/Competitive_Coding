#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;

// #define BRUTE 1
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

class Solution {
 public:
  void solve(int n) {
    vector<int> bal(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> bal[i];
    }
    vector<pair<int, pair<int, int>>> balTime(n + 1);
    for (int i = 1; i <= n; ++i) {
      balTime[i] = {0, {i, bal[i]}};
    }

    int q;
    cin >> q;
    int type, x, y;

    vector<int> done(n + 1, 0);
    vector<vector<int>> queries;
    for (int i = 0; i < q; ++i) {
      cin >> type;
      if (type == 1) {
        cin >> x >> y;

        #ifdef BRUTE
        bal[x] = y;
        #endif

        #ifndef BRUTE
        queries.push_back(vector<int> {1, x, y});
        balTime[x] = {i, {x, y}}; // time = query index
        #endif
      } else {
        cin >> x;
        #ifdef BRUTE
        for (int j = 1; j <= n; ++j) {
          if (bal[j] < x) {
            bal[j] = x;
          }
        }
        #endif

        #ifndef BRUTE
        queries.push_back(vector<int> {2, x, -1});
        #endif
      }
    }

    // sort indices based on marked time
    sort(balTime.begin() + 1, balTime.end());
    reverse(balTime.begin() + 1, balTime.end());

    /*/
    for (int ix = 1; ix <= n; ++ix) {
      int orgIdx = balTime[ix].second.first;
      int val = balTime[ix].second.second;
      int time = balTime[ix].first;
      cerr << ix << " " << orgIdx << " " << val << " " << time << endl;
    }
    //*/

    int maxProcessed = INT_MIN;
    int idx = 1;
    for (int i = q - 1; i >= 0; --i) {
      type = queries[i][0]; // 2 only
      if (type == 1) {
        continue;
      }
      int orgIdx = balTime[idx].second.first;
      int val = balTime[idx].second.second;
      int time = balTime[idx].first;
      // cerr << idx << " " << orgIdx << " " << val << " " << time << endl;
      while (idx <= n && time != 0 && time > i) {
        // cerr << idx << " " << orgIdx << " " << val << " " << time << endl;
        if (val < maxProcessed) {
          bal[orgIdx] = maxProcessed;
          done[orgIdx] = 1;
        } else {
          bal[orgIdx] = val;
          done[orgIdx] = 1;
        }
        ++idx;
        if (idx <= n) {
          orgIdx = balTime[idx].second.first;
          val = balTime[idx].second.second;
          time = balTime[idx].first;
        }
      }
      x = queries[i][1];
      if (x > maxProcessed) {
        maxProcessed = x;
      }
    }
    int orgIdx = balTime[idx].second.first;
    int val = balTime[idx].second.second;
    int time = balTime[idx].first;
    while (idx <= n && time >= 0) {
      if (val < maxProcessed) {
        bal[orgIdx] = maxProcessed;
        done[orgIdx] = 1;
      } else {
        bal[orgIdx] = val;
        done[orgIdx] = 1;
      }
      ++idx;
      if (idx <= n) {
        orgIdx = balTime[idx].second.first;
        val = balTime[idx].second.second;
        time = balTime[idx].first;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (!done[i] && bal[i] < maxProcessed) {
        bal[i] = maxProcessed;
      }
      cout << bal[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  FAST_IO;  
  int n;
  cin >> n;

  Solution solver;
  solver.solve(n);
  return 0;
}