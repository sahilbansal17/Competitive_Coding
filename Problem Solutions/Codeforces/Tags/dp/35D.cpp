#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;

    vector<int> c(n, 0), food(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        food[i] = c[i]*(n - i);
    }

    sort(food.begin(), food.end());
    int sum = 0, cur = 0;
    while (cur < n && sum + food[cur] <= x) {
        sum += food[cur];
        ++cur;
    }
    cout << cur << endl;
}