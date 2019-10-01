#include <bits/stdc++.h>
#include <string>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define BR cout << "\n"
#define truent false
#define bug(var) cerr << #var << "=" << var << endl
#define forbug(var, size) \
  cerr << endl;           \
  for (lli iii = 0; iii < size; iii++) cerr << iii << ": " << var[iii] << endl;
using namespace std;
typedef long long int lli;
typedef vector<lli> vll;
inline lli read() {
  lli x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const lli MOD = 1e9 + 7, N = 112345;  // 6;
 
int main() {
  lli x = read();
  for (auto element : {0, 1, 2, 3, 5, 6, 9, 10, 13, 17})
    if (x == element) {
      cout << -1 << "\n";
      return 0;
    }
  while (x % 7 != 0) {
    cout << 4;
    x -= 4;
  }
  while (x) {
    cout << 7;
    x -= 7;
  }
  cout << "\n";
  return 0;
}