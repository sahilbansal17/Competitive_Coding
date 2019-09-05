#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

ll solve(ll n, ll m) {
  ll res = 0;
  vector<int> marked(10, 0);

  ll multiple = m;
  ll distinctCnt = 0;
  for (int i = 1; i <= 10; ++i) {
    if (multiple > n) {
      return res;
    }
    ++distinctCnt;
    int dig = multiple % 10;
    if (marked[dig]) {
      --distinctCnt;
      break;
    }
    marked[dig] = 1;
    res += dig;
    multiple += m;
  }

  ll totalCnt = n/m;
  res = (totalCnt/distinctCnt) * res;

  ll rem = totalCnt % distinctCnt;
  multiple = m;
  for (int i = 1; i <= rem; ++i) {
    int dig = multiple % 10;
    res += dig;
    multiple += m;
  }

  return res;
}

int main() {
  FAST_IO;
  int q;
  cin >> q;

  while (q --) {
    ll n, m;
    cin >> n >> m;

    ll res = solve(n, m);
    cout << res << endl;
  }
  
  return 0;
}