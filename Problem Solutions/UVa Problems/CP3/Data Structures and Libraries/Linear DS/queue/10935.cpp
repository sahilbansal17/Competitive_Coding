#include <bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n;
    while (n != 0) {

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }

        vector<int> discarded;
        while (q.size() != 1) {
            discarded.push_back(q.front());
            q.pop();
            // move the top card to the back
            q.push(q.front());
            q.pop();
        }
        cout << "Discarded cards:";
        if (n == 1) {
            cout << endl;
        } else {
            cout << " ";
        }
        for (int i = 0; i < n - 1; ++i) {
            cout << discarded[i];
            if (i == n - 2) {
                cout << endl;
            } else {
                cout << ", ";
            }
        }
        cout << "Remaining card: " << q.front() << endl;
        cin >> n;
    }
    return 0;
}