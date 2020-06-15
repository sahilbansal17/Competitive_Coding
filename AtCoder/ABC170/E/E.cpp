#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
/**
 * Uncomment the #define below if problem contains multiple test cases
 */
// #define MULTIPLE_TESTS 1

const int MAXN = 2e5 + 10;
void solve() {
  int n, q;
  cin >> n >> q;
  int a, b;
  set<int> kg_id[MAXN];
  multiset<int> kg_rat[MAXN];
  vector<int> rat(n + 1, 0);
  vector<int> cur(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    kg_id[b].insert(i + 1);
    kg_rat[b].insert(a);
    rat[i + 1] = a;
    cur[i + 1] = b;
  }
  multiset<int> pq;
  for (int i = 0; i < MAXN; ++i) {
    if (kg_rat[i].size() > 0) {
      int maxi = *kg_rat[i].rbegin();
      pq.insert(maxi);
    }
  }
  int c, d;
  for (int i = 0; i < q; ++i) {
    cin >> c >> d;
    // cth student to dth kg
    int act = cur[c];
    int cur_rat = rat[c];
    // erase
    int actual_maxi = *kg_rat[act].rbegin();
    auto itr2 = pq.find(actual_maxi);
    pq.erase(itr2);

    auto itr = kg_rat[act].find(cur_rat);
    kg_rat[act].erase(itr);
    kg_id[act].erase(c);

    int new_maxi;
    if (kg_rat[act].size() > 0) {
      new_maxi = *kg_rat[act].rbegin();
      pq.insert(new_maxi);
    }
    // add
    if (kg_rat[d].size() > 0) {
      actual_maxi = *kg_rat[d].rbegin();
      auto itr3 = pq.find(actual_maxi);
      pq.erase(itr3);
    }
    cur[c] = d;
    kg_id[d].insert(c);
    kg_rat[d].insert(cur_rat);
    new_maxi = *kg_rat[d].rbegin();
    pq.insert(new_maxi);

    int ans = *pq.begin();
    cout << ans << endl;
  }
}

int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  while (t--) {
    solve();
  }

  return 0;
}