#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;

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
  int solve(int n, int intensity, vector<int> a) {
    int kreq = (intensity*8)/n;
    // cerr << "k required: " << kreq << endl;

    if (kreq > 20) {
      kreq = 20;
    }

    int distinctReq = min(n, power(2, kreq));
    // cerr << "distinctReq: " << distinctReq << endl;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i]];
    }

    int total = cnt.size();
    // cerr << "total: " << total << endl;

    if (distinctReq >= total) {
      return 0;
    }

    int windowSum = 0;
    auto itEnd = cnt.begin();
    advance(itEnd, distinctReq);

    auto itStart = cnt.begin();
    for (auto it2 = itEnd; it2 != cnt.end(); ++it2) {
      windowSum += it2->second;
    }
    // cerr << windowSum << endl;
    int ans = windowSum;
    while (itEnd != cnt.end()) {
      windowSum += itStart->second;
      windowSum -= itEnd->second;
      ++itStart;
      ++itEnd;
      ans = min(ans, windowSum);
      // cerr << windowSum << endl;
    }
    return ans;
  }
};

int main() {
  FAST_IO;
  int n, I;
  cin >> n >> I;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, I, a);
  return 0;
}