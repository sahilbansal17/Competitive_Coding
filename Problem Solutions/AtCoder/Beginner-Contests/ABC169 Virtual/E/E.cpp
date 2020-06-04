#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

void readArray(vector<ll>& arr, int n) {
    arr.resize(n);
    for (auto &a: arr) {
        cin >> a;
    }
}

void readParallelArrays(vector<ll>& arr1, vector<ll>& arr2, int n) {
    arr1.resize(n);
    arr2.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
        cin >> arr2[i];
    }
}

void sortArray(vector<ll>& arr) {
    sort(arr.begin(), arr.end());
}

void solve() {
    int n;
    cin >> n;
    vector<ll> A, B;
    readParallelArrays(A, B, n);
    sortArray(A);
    sortArray(B);
    ll ans;
    if (n & 1) {
        int mid = n/2;
        ans = B[mid] - A[mid] + 1;
    } else {
        int mid1 = (n - 1)/2;
        int mid2 = n/2;
        ll A_mid = (A[mid1] + A[mid2]);
        ll B_mid = (B[mid1] + B[mid2]);
        ans = (B_mid - A_mid + 1);
    }
    cout << ans << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    #ifdef MULTIPLE_TESTS
    cin >> t;
    #endif

    while (t--) {
        solve();
    }

    return 0;
}