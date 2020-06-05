#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

template<typename T> 
inline void readArray(vector<T>& arr, int n);
template<typename T>
inline void printArray(vector<T>& arr);
template<typename T>
inline void sortArray(vector<T>& arr);

void solve() {
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> t;
    readArray(t, n);
    vector<pair<int, int>> with_id;
    for (int i = 0; i < n; ++i) {
        with_id.push_back({t[i], i});
    }
    sort(with_id.begin(), with_id.end());
    
    vector<int> done(n, 1);
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        int cur = with_id[i].second;
        int topic = with_id[i].first;
        if (done[cur] != topic) {
            cout << -1 << endl;
            return;
        }
        for (auto x: adj[cur]) {
            if (done[x] == topic) {
                ++done[x];
            }
        }
        p.push_back(cur + 1);
    }
    printArray(p);
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