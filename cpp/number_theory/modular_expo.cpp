// x^n % m
int binaryExponentiation(int x, int n, int m) {
  int res = 1;
  x %= m;
  while (n > 0) {
    if (n & 1) {
      res *= x;
      res %= m;
    }
    x *= x;
    x %= m;
    n >>= 1;
  }
  return res;
}
