/*
 * Problem link: https://codeforces.com/contest/622/problem/C
 * Category: Segment Tree based
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAX = 200010;
// store the indices of min/max elements in the segment trees
vector<int> stMin(4*MAX);
vector<int> stMax(4*MAX);
int buildTree(bool op, int i, int start, int end, vector<int> &a) {
  // base case
  if (start == end) {
    if (op == 1) {
      stMax[i] = start;
    } else {
      stMin[i] = start;
    }
    return start;
  }
  int mid = (start + end) >> 1;
  // left
  int left = buildTree(op, 2*i, start, mid, a);
  // right
  int right = buildTree(op, 2*i + 1, mid + 1, end, a);
  // find value for current node
  int cur;
  if (op == 1) {
    if (a[left] > a[right]) {
      cur = left;
    } else {
      cur = right;
    }
    stMax[i] = cur;
  } else {
    if (a[left] > a[right]) {
      cur = right;
    } else {
      cur = left;
    }
    stMin[i] = cur;
  }
  return cur;
}

int query(bool op, int idx, int ql, int qr, int st, int en, vector<int> &a) {
  // no overlap
  if (qr < st) {
    return -1;
  }
  if (ql > en) {
    return -1;
  }
  // complete overlap
  if (ql <= st && en <= qr) {
    if (op == 1) {
      return stMax[idx];
    } else {
      return stMin[idx];
    }
  }

  // partial overlap
  int mid = (st + en) >> 1;
  // left
  int left = query(op, 2*idx, ql, qr, st, mid, a);
  // right
  int right = query(op, 2*idx + 1, ql, qr, mid + 1, en, a);
  if (left == -1) {
    return right;
  } else if (right == -1) {
    return left;
  } else {
    if (op == 1) {
      // max query
      if (a[left] > a[right]) {
        return left;
      } else {
        return right;
      }
    } else {
      // min query
      if (a[left] > a[right]) {
        return right;
      } else {
        return left;
      }
    }
  }
}

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  // minimum
  buildTree(0, 1, 1, n, arr); // op, idx, st, en, arr
  // maximum
  buildTree(1, 1, 1, n, arr);
  int l, r, x;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r >> x;
    int minIdx = query(0, 1, l, r, 1, n, arr); // op, idx, ql, qr, st, en, arr
    int maxIdx = query(1, 1, l, r, 1, n, arr); 
    if (arr[minIdx] == arr[maxIdx] && arr[minIdx] == x) {
      cout << "-1" << endl;
    } else if (arr[minIdx] != x) {
      cout << minIdx << endl;
    } else {
      cout << maxIdx << endl;
    }
  }
  return 0;
}