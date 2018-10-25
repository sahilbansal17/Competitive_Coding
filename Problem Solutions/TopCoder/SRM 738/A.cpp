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

class DriveTheCarEasy{
public:
	long long calculateDistance(int S, int N, vector <int> speed_changes, vector <int> moments) {
		ll res = 0, speed = 0, ct = 1, pt = 1;
		vector < pii > v;
		rep (i, N) {
			v.pb(mp(moments[i], speed_changes[i]));
		}
		srt(v);
		rep (i, N - 1) {
			speed += v[i].S;
			pt = v[i].F;
			ct = v[i + 1].F;
			res += (ct - pt)*speed;
			// cout << res << endl;
		}
		speed += v[N - 1].S;
		pt = v[N - 1].F;
		ct = S;
		// cout << pt << " " << ct << endl;
		// cout << speed << endl;
		res += (ct - pt + 1)*speed;
		return res;
	}

};

int main(){

	DriveTheCarEasy a;
	
	cout << "\n" << a.calculateDistance(5, 5, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}) << "\n";
}