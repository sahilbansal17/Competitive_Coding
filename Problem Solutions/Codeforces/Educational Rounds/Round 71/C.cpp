#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
  FAST_IO;  
  int t;
  cin >> t;

  while (t --) {
    ll n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    ll count1 = 0, count2 = 0;
    ll switches = 0;

    ll cost1 = 0, cost2 = 0;
    ll res = 0;
    int i = 0;
    int j = i;
    while (i < n && s[i] == '0') {
      ++i;
    }
    count1 += (i - j);
    if (i != n) {
      ++switches;
      count2 += 1;
    } else {
      ++count1;
    }

    while (i < n) {      
      j = i;
      while (i < n && s[i] == '1') {
        ++i;
      }
      count2 += (i - j);

      j = i;
      while (i < n && s[i] == '0') {
        ++i;
      }
      if (i == n) {
        ++switches;
        count1 += (i - j);
      } else if (i - j >= 2) {
        cost1 = (i - j)*a + 2*a + (i - j)*b + b; 
        cost2 = (i - j)*a + 2*(i - j)*b;
        if (cost1 < cost2) {
          count1 += (i - j - 1);
          count2 += 1;
          switches += 2;
        } else {
          count2 += (i - j);
        }
      } else {
        ++count2;
      }
    }

    res += count1*b;
    res += 2*count2*b;
    res += (n)*a;
    res += switches*a;
    cout << res << endl;
  }

  return 0;
}