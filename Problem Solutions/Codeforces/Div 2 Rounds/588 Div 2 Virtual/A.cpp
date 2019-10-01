/*
 * Problem Link: https://codeforces.com/contest/1230/problem/A
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

  int a[4];
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }

  sort(a, a + 4);
  if (a[0] + a[3] == a[1] + a[2]) {
    cout << "YES";
  } else if (a[0] + a[1] + a[2] == a[3]) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}