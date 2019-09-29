int Solution::diffPossible(const vector<int> &A, int k) {
  int n = A.size();
  unordered_map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    ++cnt[A[i]];
    if (A[i] - k != A[i] && cnt[A[i] - k] > 0) {
      return 1;
    }
    if (A[i] - k == A[i] && cnt[A[i]] > 1) {
      return 1;
    }
  }
  return 0;
}