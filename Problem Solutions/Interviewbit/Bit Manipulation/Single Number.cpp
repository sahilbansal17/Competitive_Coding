int Solution::singleNumber(const vector<int> &A) {
  int res = 0;
  int n = A.size();
  for (int i = 0; i < n; ++i) {
    res ^= A[i];
  }
  return res;
}