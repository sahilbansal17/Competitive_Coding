#include <bits/stdc++.h>
using namespace std;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

class TreeLine{
    public:
    int longest(vector <int> x, vector <int> y) {
        int res = 0, cur_res = 0;
        int n = x.size();
        map <pair <int, int>, int> cnt;
        for (int i = 0; i < n; i ++) {
            int vertical = 0;
            cur_res = 0;
            for (int j = i + 1; j < n; j ++) {
                if (x[i] == x[j]) {
                    vertical ++;
                }
                else {
                    int xx = x[j] - x[i];
                    int yy = y[j] - y[i];
                    int d = gcd(xx, yy);
                    if (d != 0) {
                        xx /= d;
                        yy /= d;
                    }
                    cnt[{xx, yy}] ++;
                    cur_res = max(cur_res, cnt[{xx, yy}]);
                }
                cur_res = max(cur_res, vertical);
            }
            res = max(res, cur_res + 1);
            cnt.clear();
        }
        return res;
    }   
};