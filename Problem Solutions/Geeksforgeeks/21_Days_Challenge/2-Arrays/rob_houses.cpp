#include <bits/stdc++.h>
using namespace std;

int maxMoney(int arr[], int num) {
    int cur = 0;
    int res = 0;
    int cur_sum = 0;
    bool cycle_done = false;
    while (cur < num && !cycle_done) {
        int next = cur;
        int count = 0;
        while (next < num) {
            cur_sum += arr[next];
            ++count;
            if (cur_sum <= 0) {
                if (cycle_done) {
                    break;
                }
                count = 0;
                cur_sum = 0;
            }
            res = max(res, cur_sum);
            next = (next + 1) % num;
            if (next == 0) {
                cycle_done = true;
            }
            if (count == num) {
                break;
            }
        }
        cur = next + 1;
    }
    return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    cout << maxMoney(arr, num) << endl;
  }
  return 0;
}