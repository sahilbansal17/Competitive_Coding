typedef long long ll;
vector<int> Solution::lszero(vector<int> &A) {
  unordered_map<ll, int> indexFirstSeen;
  int n = A.size();

  ll prefixSum = 0;
  ll maxLength = 0;
  ll start = -1;
  for (int i = 0; i < n; ++i) {
    prefixSum += 1ll * A[i];

    if (prefixSum == 0) {
      maxLength = i + 1;
      start = 0;
    } else if (indexFirstSeen.find(prefixSum) != indexFirstSeen.end()) {
      int idx = indexFirstSeen[prefixSum];
      if (i - idx > maxLength) {
        maxLength = i - idx;
        start = idx + 1;
      }
    } else {
      indexFirstSeen[prefixSum] = i;
    }
  }
  vector<int> res;
  for (int i = start; i < start + maxLength; ++i) {
    res.push_back(A[i]);
  }
  return res;
}
