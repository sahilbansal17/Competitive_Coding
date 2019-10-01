const int MOD = 10003;

bool isVowel(char ch) {
  if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
      ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
    return 1;
  }
  return 0;
}

int Solution::solve(string A) {
  int n = A.length();
  int res = 0;

  for (int i = 0; i < n; ++i) {
    if (isVowel(A[i])) {
      res += (n - i);
      res %= MOD;
    }
  }
  return res;
}