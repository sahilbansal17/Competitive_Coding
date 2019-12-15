#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

#define MAX 1000000000
int findCount(vector<pair<int, int> >& pts, int px, int py, int sx, int sy) {
    int cnt = 0, x, y;
    for (int i = 0; i < pts.size(); ++i) {
        x = pts[i].first;
        y = pts[i].second;
        bool possibleX = false;
        bool possibleY = false;
        if (sx <= px && px <= x) {
            possibleX = true;
        } else if (x <= px && px <= sx) {
            possibleX = true;
        }
        if (sy <= py && py <= y) {
            possibleY = true;
        } else if (y <= py && py <= sy) {
            possibleY = true;
        }
        if (possibleX && possibleY) {
            ++cnt;
        }
    }
    return cnt;
}
int main() {
    FAST_IO;

    int n, sx, sy;
    cin >> n >> sx >> sy;

    vector<pair<int, int> > pts;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        pts.push_back({x, y});
    }

    int dx[4] = {-1, 0, 0, +1};
    int dy[4] = {0, -1, +1, 0};
    
    int resCnt = 0;
    int curCnt = 0;
    int resX = -1, resY = -1;
    for (int k = 0; k < 4; ++k) {
        int nx = sx + dx[k];
        int ny = sy + dy[k];
        if (0 <= nx && nx <= MAX && 0 <= ny && ny <= MAX) {
            curCnt = findCount(pts, nx, ny, sx, sy);
            if (curCnt > resCnt) {
                resCnt = curCnt;
                resX = nx;
                resY = ny;
            }
        }
    }

    cout << resCnt << endl;
    cout << resX << " " << resY << endl;
    return 0;
}