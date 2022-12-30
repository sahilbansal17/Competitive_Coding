#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1

template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}

// Create map that stores number of prefix array
// elements corresponding to a XOR value
vector<int> xorArr;

long long subarrayXor(vector<int>& arr, int n)
{
    long long ans = 0; // Initialize answer to be returned
 
    vector<int> mp(2*n + 1, 0);

    // Calculate the answer
    for (int i = 0; i < n; i++) {
       
        // Find XOR of current prefix with m.
        for (int j = 0; j <= sqrt(2*n); ++j) {
          int tmp = (j*j) ^ xorArr[i];
          // If above XOR exists in map, then there
          // is another previous prefix with same
          // XOR, i.e., there is a subarray ending
          // at i with XOR equal to m.
          if (tmp <= 2*n) {
            ans = ans + ((long long)mp[tmp]);
          }
 
          // If this subarray has XOR equal to m itself.
          if (xorArr[i] == (j*j))
            ans++;
        }
 
        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }
 
    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
}

void initialize(vector<int>& arr) {
 
  xorArr.push_back(arr[0]);
 
  // Computing the prefix array.
  for (int i = 1; i < arr.size(); i++) {
    xorArr.push_back(xorArr[i - 1] ^ arr[i]);
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> arr;
  readArray(arr, n);
  initialize(arr);

  ll cnt = subarrayXor(arr, n);

  ll total = 1ll * n * (n + 1) / 2;
  cout << total - cnt << endl;

  xorArr.clear();
  // we need to find the no of subarrays whose xor is perfect square

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