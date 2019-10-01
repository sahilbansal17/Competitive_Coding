int jumpingOnClouds(vector<int> c) {
  int n = c.size();
  vector<int> dp(n, 10000);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (c[i] == 1) {
      continue;
    }
    if (i - 1 >= 0) {
      dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    if (i - 2 >= 0) {
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
  }
  return dp[n - 1];
}
