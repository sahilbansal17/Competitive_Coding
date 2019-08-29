#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int MAX = 300010;
ll fact[MAX];
const ll MOD = 998244353;

int main() {
  FAST_IO;  
  int n;
  cin >> n;

  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  vector<pair<int, int>> vp(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i].first >> vp[i].second;
    a[i] = vp[i].first;
    b[i] = vp[i].second;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(vp.begin(), vp.end());

  ll countA = 1, countB = 1, countAnB = 1;

  int i = 0;
  while (i < n) {
    int j = i;
    ll cc = 0;
    while (i < n && a[i] == a[j]) {
      ++cc;
      ++i;
    }
    countA *= fact[cc];
    countA %= MOD;
  }
  i = 0;
  while (i < n) {
    int j = i;
    ll cc = 0;
    while (i < n && b[i] == b[j]) {
      ++cc;
      ++i;
    }
    countB *= fact[cc];
    countB %= MOD;
  }

  bool sorted = true; 
  for (int k = 0; k < n; ++k) {
    if (k + 1 < n && vp[k].first > vp[k + 1].first) {
      sorted = false;
      break;
    }
    if (k + 1 < n && vp[k].second > vp[k + 1].second) {
      sorted = false;
      break;
    }
  }

  ll res;
  if (!sorted) {
    res = (countA + countB) % MOD;
  } else {
    i = 0;
    while (i < n) {
      int j = i;
      ll cc = 0;
      while (i < n && vp[i] == vp[j]) {
        ++cc;
        ++i;
      }
      countAnB *= fact[cc];
      countAnB %= MOD;
    }
    res = (countA + countB) % MOD;
    res = (res - countAnB + MOD) % MOD;
  }

  res = (fact[n] - res + MOD) % MOD;
  cout << res << endl;

  return 0;
}