#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

struct point {
    double x, y;
    point(double x_, double y_) : x(x_), y(y_) { }
};

double area(vector<point>& pts) {
    int n = pts.size();
    double total = 0;
    int j = n - 1;
    for (int i = 0; i < n; ++i) {
        total += (pts[j].x + pts[i].x) * (pts[j].y - pts[i].y);
        j = i;
    } 
    total = abs(total);
    double res = total/2.0;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<point> pts;
    double x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        pts.push_back(point((x[i] + x[i + 1])/2., (y[i] + y[i + 1])/2.));
    }
    pts.push_back(point((x[0] + x[n - 1])/2., (y[0] + y[n - 1])/2.));

    cout << fixed;
    cout << setprecision(9) << area(pts) << endl;
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}