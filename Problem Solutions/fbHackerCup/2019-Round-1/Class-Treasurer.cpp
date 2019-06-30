#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
const int MOD = 1000000007;
typedef long long ll;

ll pow2[MAX];

ll solve(int n, int k, string &s) {
  // greedy approach, min cost
  reverse(s.begin(), s.end());

  // max subarray sum should not exceed k
  int curSubArraySum = 0;
  ll res = 0;
  // int count = 0;
  for (int i = 0; i < n; i ++) {
    if (s[i] == 'A') {
      // A -> -1
      curSubArraySum --;
    } else {
      // B -> 1
      curSubArraySum ++;
    }

    if (curSubArraySum > k) {
      // count ++;
      res += pow2[n - i];
      res %= MOD;
      curSubArraySum -= 2;
    }
    if (curSubArraySum <= 0) {
      curSubArraySum = 0;
    }
  }
  // cerr << count << endl;
  return res;
}

void initializePowersOf2() {
  ll res = 1;
  pow2[0] = res;
  for (int i = 1; i <= MAX; i ++) {
    res *= 2;
    res %= MOD;
    pow2[i] = res;
  }
  return ;
}

int main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/Users/sahilbansal/Downloads/class_treasurer.txt", "r", stdin);
  // freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  // freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  // freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  // #endif

  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);

  int t;
  cin >> t;

  initializePowersOf2();

  for (int i = 0; i < t; i ++) {
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll res = solve(n, k, s);

    cout << "Case #" << i + 1 << ": " << res << endl;
    
  } 

  return 0;
}