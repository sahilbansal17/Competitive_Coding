#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const int MAXN = 2e5 + 10;
int arr[MAXN];

using mykey = pair<int, pair<int, int>>;
struct mycompare{
    bool operator()(const mykey& k1, const mykey& k2) {
        int l1 = k1.first; // length of first 
        int l2 = k2.first; // length of second
        if (l1 != l2) {
            return l1 < l2; // return 1 if l1 is not larger
        }
        int i1 = k1.second.first; // start index of first
        int i2 = k2.second.first; // start index of second;
        return i1 > i2; // reutrn 1 if i1 is not smaller
    }
};
priority_queue<mykey, vector<mykey>, mycompare> pq;

void solve() {
    int n;
    cin >> n;

    int k = 1; // value to be updated in array, action number

    // push the starting interval (0, n - 1)
    pq.push({n, {0, n - 1}});
    int len, mid, right, left;
    while (!pq.empty()) {
        mykey fr = pq.top(); // max length interval to be chosen
        pq.pop();
        len = fr.first; // length
        left = fr.second.first; // left index
        right = fr.second.second; // right index
        if (left == right) {
            arr[left] = k++; // update the value
            continue;
        }
        // find mid
        if (len & 1) {
            mid = (left + right)/2;
        } else {
            mid = (left + right - 1)/2;
        }
        arr[mid] = k++;
        if (mid + 1 <= right) { // {start, end} should be valid
            pq.push({right - mid, {mid + 1, right}});
        }
        if (left <= mid - 1) {
            pq.push({mid - left, {left, mid - 1}});
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}