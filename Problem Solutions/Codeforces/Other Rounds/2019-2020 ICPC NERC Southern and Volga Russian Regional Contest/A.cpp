/*
 * Problem Link: https://codeforces.com/contest/1250/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    int n, m;
    cin >> n >> m;

    vector<int> curPos(n + 1), minPos(n + 1), maxPos(n + 1);
    vector<int> postAtPos(n + 1);
    for (int i = 1; i <= n; ++i) {
        curPos[i] = i;
        minPos[i] = i;
        maxPos[i] = i;
        postAtPos[i] = i;
    }

    int curLikedPost;
    for (int i = 0; i < m; ++i) {
        cin >> curLikedPost;
        if (curPos[curLikedPost] != 1) {
            int position = curPos[curLikedPost];
            // swap with the higher post ( position - 1 )
            int nextHigherPost = postAtPos[position - 1];
            curPos[curLikedPost] = position - 1;
            curPos[nextHigherPost] = position;
            postAtPos[position] = nextHigherPost;
            postAtPos[position - 1] = curLikedPost;
            minPos[curLikedPost] = min(minPos[curLikedPost], curPos[curLikedPost]);
            minPos[nextHigherPost] = min(minPos[nextHigherPost], curPos[nextHigherPost]);
            maxPos[curLikedPost] = max(maxPos[curLikedPost], curPos[curLikedPost]);
            maxPos[nextHigherPost] = max(maxPos[nextHigherPost], curPos[nextHigherPost]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << minPos[i] << " " << maxPos[i] << endl;
    }
    
    return 0;
}