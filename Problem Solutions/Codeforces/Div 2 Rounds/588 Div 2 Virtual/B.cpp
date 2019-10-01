/*
 * Problem Link: https://codeforces.com/contest/1230/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
  FAST_IO;
  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif 

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  // corner case
  if (n == 1 && k == 1) {
    cout << "0" << endl;
    return 0;
  }

  if (s[0] != '1' && k >= 1) {
    s[0] = '1';
    --k;
    if (k == 0) {
      cout << s << endl;
      return 0;
    }
  }

  for (int i = 1; i < n; ++i) {
    if (s[i] != '0' && k >= 1) {
      s[i] = '0';
      --k;
      if (k == 0) {
        cout << s << endl;
        return 0;
      }
    }
  }

  cout << s << endl;
  return 0;
}