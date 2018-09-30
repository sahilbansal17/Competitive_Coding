#include <vector>
#include <numeric>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <regex>
#include <cmath>
#include <map>
#include <unordered_map>
#include <iterator>
#include <queue>

using namespace std;

void vasya_and_multiset (const vector<int>& v) {
  unordered_map<int, int> m;
  for (auto e : v) ++m[e];

  auto eq1      = [](const auto& e) { return e.second == 1; };
  auto gt2      = [](const auto& e) { return e.second >  2; };
  auto ones     = count_if (m.begin (), m.end (), eq1);
  auto has_gt2  = any_of   (m.begin (), m.end (), gt2);
  auto odd_ones = ones % 2 == 1;

  if (odd_ones && !has_gt2) cout << "NO\n";
  else {
     cout << "YES\n";
     auto A = true;
     for (auto e : v) {
        if      (m[e] == 2) cout << 'B'; // or 'A', doesn't matter
        else if (m[e] == 1) cout << (A ? 'A' : 'B'), A = !A;
        else {
           if (odd_ones) cout << 'B', odd_ones = false;
           else          cout << 'A';
        }
     }
     cout << endl;
  }
}

int main () {
   int n; cin >> n;
   vector<int> v (n);
   for (int i = 0; i < n; ++i) cin >> v[i];
   vasya_and_multiset (v);
   return 0;
}