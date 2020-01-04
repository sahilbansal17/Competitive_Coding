#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int my_solution(vector<int>& a) {
    unordered_map<int, deque<int> > indexes;
    unordered_map<int, int> mapping = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};

    int n = a.size();
    for (int i = 0; i < n; ++i) {
        indexes[mapping[a[i]]].push_back(i);
    }

    bool done = false;
    int removed = 0;
    while (!done) {
        if (indexes[0].size() == 0) {
            done = true;
            break;
        }
        int cur = indexes[0].front();
        for (int i = 1; i < 6; ++i) {
            while (indexes[i].size() > 0 && indexes[i].front() < cur) {
                indexes[i].pop_front();
                ++removed;
            }
            if (indexes[i].size() == 0) {
                done = true;
                break;
            }
            cur = indexes[i].front();
        }
        if (!done) {
            // can move forward, remove the top from each deque
            for (int i = 0; i < 6; ++i) {
                indexes[i].pop_front();
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        removed += indexes[i].size();
    }
    return removed;
}

int editorial_solution(vector<int>& a) {
    vector<int> p({4, 8, 15, 16, 23, 42}); // wow, a new way to initialize vectors

    int n = a.size();
    // assign values 0, 1, 2, 3, 4 and 5 to these 6 different values
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
    }

    vector<int> cnt(6, 0);
    // cnt[i] represents the count of the subsequences [0, 1, ... i]
    // eg cnt[3] represents the count of the subsequences [0, 1, 2, 3]
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++cnt[0];
        } else if (cnt[a[i] - 1] > 0) {
            // better to include in a subsequences containing all prev. till (a[i] - 1)
            --cnt[a[i] - 1];
            ++cnt[a[i]];
        }
    }

    int removed = n - 6*cnt[5];
    return removed;
}

int main() {
    FAST_IO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << editorial_solution(a) << endl;
    
    return 0;
}