#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

bool based_on_end_time(pair<int, pair<int, int>> act_1, pair<int, pair<int, int>> act_2) {
    if (act_1.second.second == act_2.second.second) {
        return act_1.second.first > act_2.second.first;
    }
    return act_1.second.second < act_2.second.second;
}
bool based_on_start_time(pair<int, pair<int, int>> act_1, pair<int, pair<int, int>> act_2) {
    if (act_1.second.first == act_2.second.first) {
        return act_1.second.second < act_2.second.second;
    }
    return act_1.second.first < act_2.second.first;
}
void solve(int case_no) {
    
    int n;
    cin >> n;
    int s, e;
    vector<pair<int, pair<int, int>>> activities;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        activities.push_back({i, {s, e}});
    }
    // sort based on ending times
    sort(activities.begin(), activities.end(), based_on_start_time);
    
    vector<int> cnt(24*60 + 2, 0);
    for (int i = 0; i < n; ++i) {
        int cur_start = activities[i].second.first;
        int cur_end = activities[i].second.second;

        // cout << cur_start << " " << cur_end << endl;
        cnt[cur_start] += 1;
        cnt[cur_end] -= 1;
    }

    bool possible = true;
    if (cnt[0] >= 3) {
        possible = false;
    }
    for (int i = 1; i <= 24*60; ++i) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] >= 3) {
            possible = false;
        }
    }
    vector<char> res(n);
    int j_ending = -1;
    int c_ending = -1;
    for (int i = 0; i < n; ++i) {
        int cur_start = activities[i].second.first;
        int cur_end = activities[i].second.second;
        int idx = activities[i].first;
        if (cur_start >= j_ending) {
            res[idx] = 'J';
            j_ending = cur_end;
        } else {
            res[idx] = 'C';
            c_ending = cur_end;
        }
    }
    cout << "Case #" << case_no << ": ";
    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << res[i];
        }
        cout << endl;
    }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int id = 1; id <= t; ++id) {
        solve(id);
    }
    
    return 0;
}