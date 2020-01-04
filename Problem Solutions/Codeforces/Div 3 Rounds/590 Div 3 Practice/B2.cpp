#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n, k;
    cin >> n >> k;

    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        cin >> id[i];
    }

    // as mentioned in the editorial:
    // And don't forget that std::unordered_map and 
    // other standard hashmaps can work in linear time in the worst case, 
    // so you need to redefine the hash function to use them.
    // so, better let's use a set
    set<int> done;
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        if (done.find(id[i]) != done.end()) {
            continue;
        }
        if (dq.size() < k) {
            dq.push_front(id[i]);
        } else {
            int last = dq.back();
            dq.pop_back();
            done.erase(last);
            dq.push_front(id[i]);
        }
        done.insert(id[i]);
    }

    cout << dq.size() << endl;
    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    return 0;
}