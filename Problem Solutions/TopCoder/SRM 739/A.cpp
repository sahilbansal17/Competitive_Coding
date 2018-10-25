#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rfl(i, a, b)    for(int i(a); i >= (b); i --)
#define srt(v)          sort((v).begin(), (v).end())
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
const ll MOD = 1000000007LL;
const ll MAX = 2000000007LL;

class HungryCowsEasy{
public:
	vector <int> findFood(vector <int> c, vector <int> b) {
		int cn = c.size(), bn = b.size();
		vi res(cn);
		rep (i, cn) {
			int dist = MAX, cur_res = -1, check;
			rep (j, bn) {
				check = abs(b[j] - c[i]);
				if (check < dist) {
					dist = check;
					cur_res = j;
				}
				else if (check == dist && b[j] < b[cur_res]) {
					cur_res = j;
				}
			}
			res[i] = cur_res;
		}
		return res;
	}

};