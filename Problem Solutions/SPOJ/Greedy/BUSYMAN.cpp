#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool sort_by_end(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

bool compatible(pair<int, int> a, pair<int, int> b) {
    return a.second <= b.first;
}

int main () {

    int t;
    cin >> t;

    int n, x, y;
    while (t--) {
        cin >> n;

        vector<pair<int, int>> activities;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            activities.push_back({x, y});
        }

        sort(activities.begin(), activities.end(), sort_by_end);

        int res = 1;
        pair<int, int> prev = activities[0];
        for (int cur = 1; cur < n; ++cur) {
            if (compatible(prev, activities[cur])) {
                ++res;
                prev = activities[cur];
            }
        }

        cout << res << endl;
    }
    return 0;
}