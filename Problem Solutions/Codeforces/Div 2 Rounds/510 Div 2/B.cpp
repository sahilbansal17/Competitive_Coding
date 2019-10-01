#include <bits/stdc++.h>
#define lli long long int
#define vll vector<lli>
#define mp make_pair
#define ff first
#define ss second
#define BR cout << endl
#define truent false
#define bug(bleh) cerr << #bleh << "=" << bleh << endl
#define forbug(BL, EH) \
  cerr << endl;        \
  for (lli iii = 0; iii < EH; iii++) cerr << iii << ": " << BL[iii] << endl;
using namespace std;
const lli MOD = 1000000007, N = 123456;
lli a[N];
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

int main() {
  lli n = read(), m;
  string s;
  lli a, b, c, ab, ac, bc, abc;
  a = b = c = ab = ac = bc = abc = MOD;
  for (lli i = 0; i < n; i++) {
    cin >> m >> s;
    int x = 0, y = 0, z = 0;
    for (char c : s) {
      if (c == 'A') x++;
      if (c == 'B') y++;
      if (c == 'C') z++;
    }
    if (x) a = min(a, m);
    if (y) b = min(b, m);
    if (z) c = min(c, m);
    if (x && y) ab = min(ab, m);
    if (x && z) ac = min(ac, m);
    if (z && y) bc = min(bc, m);
    if (x && y && z) abc = min(abc, m);
  }
  lli ans = min(a + b + c, min(a + bc, min(ab + c, min(ac + b, abc))));
  cout << ((ans != MOD) ? (ans) : (-1)) << endl;
  return 0;
}