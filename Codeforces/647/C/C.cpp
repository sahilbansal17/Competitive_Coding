#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define MULTIPLE_TESTS 1

template<typename T> 
inline void readArray(vector<T>& arr, int n);
template<typename T>
inline void printArray(vector<T>& arr);
template<typename T>
inline void sortArray(vector<T>& arr);

void solve() {
    ll n;
    cin >> n;

    ll res = 0;
    for (int i = 63; i >= 0; --i) {
        if (n & (1ll << i)) {
            // cout << i << endl;
            res += (1ll << (i + 1)) - 1;
        }
    }
    cout << res << endl;
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

template<typename T>
inline void readArray(vector<T>& arr, int n) {
    arr.resize(n);
    for (auto &element: arr) {
        cin >> element;
    }
}
template<typename T>
inline void printArray(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << endl;
}
template<typename T>
inline void sortArray(vector<T>& arr) {
    sort(arr.begin(), arr.end());
}