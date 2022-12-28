bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  for (int x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}

vector<int> getFactors(int n) {
  vector<int> facts;
  for (int x = 2; x * x <= n; ++x) {
    while (n % x == 0) {
      facts.push_back(x);
      n /= x;
    }
  }
  if (n > 1) {
    facts.push_back(n);
  }
  return facts;
}