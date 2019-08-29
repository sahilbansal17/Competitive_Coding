#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int power2(int y) {
  int res = 1;
  while (y) {
    res *= 2;
    --y;
  }
  return res;
}

int main() {
  FAST_IO;
  int x = 0, xor1, xor2;

  vector<int> setA, setB;
  int maxi = power2(14) - 1;

  for (int i = 0; i < maxi; ++i) {
    bool oddOff = true;
    bool evenOff = true;
    for (int j = 0; j < 14; ++j) {
      if (i & (1 << j)) { // j-th bit is set
        if (j & 1) { // odd bit is set
          oddOff = false;
        } else {
          evenOff = false;
        }
      }
    }
    if (oddOff) { // all odd bits are off
      setA.push_back(i);
    } else if (evenOff) { // all even bits are off
      setB.push_back(i);
    }
  }

  cout << "? ";
  for (int i = 0; i < 100; ++i) {
    cout << setA[i] << " ";
  }
  cout << endl;
  cout.flush();
  cin >> xor1;

  cout << "? ";
  for (int i = 0; i < 100; ++i) {
    cout << setB[i] << " ";
  }  
  cout << endl;
  cout.flush();
  cin >> xor2;

  // processing
  int pow2 = 1;
  for (int j = 0; j < 14; ++j) {
    if (j & 1) { // odd bits are actual in xor1
      if (xor1 & (1 << j)) {
        x += pow2;
      }
    } else { // even bits are actual in xor2
      if (xor2 & (1 << j)) {
        x += pow2;
      }
    }
    pow2 *= 2;
  }

  cout << "! " << x << endl;
  cout.flush();
  return 0;
}