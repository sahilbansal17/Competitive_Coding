#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rep1(i, n)       fl(i, 1, n)
#define rfl(i, a, b)    for(int i(a); i >= (b); i --)
#define srt(v)          sort((v).begin(), (v).end())
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
const ll MOD = 1000000007LL;

class ForumPostMedium{
public:
	string getShownPostTime(string ct, string pt) {
		string hc, hp, mc, mp, sc, sp;
		hc += ct[0];
		hc += ct[1];
		mc += ct[3];
		mc += ct[4];
		sc += ct[6]; 
		sc += ct[7];
		sp += pt[6];
		sp += pt[7];
		mp += pt[3];
		mp += pt[4];
		hp += pt[0];
		hp += pt[1];
		int h1, h2, m1, m2, s1, s2;
		h1 = stoi(hc);
		m1 = stoi(mc);
		s1 = stoi(sc);
		s2 = stoi(sp);
		m2 = stoi(mp);
		h2 = stoi(hp);
		// cout << h1 << ":" << m1 << ":" << s1 << "\n";
		// cout << h2 << ":" << m2 << ":" << s2 << "\n";

		int t1 = h1*3600 + m1*60 + s1;
		int t2 = h2*3600 + m2*60 + s2;

		int hr_limit = 59*60 + 59;

		if (t1 - t2 >= 0 && t1 - t2 <= 59) {
			return "few seconds ago";
		}

		rep1 (i, 60) {
			if (t1 - t2 >= i*60 && t1 - t2 <= i*60 + 59) {
				return to_string(i) + " minutes ago";
			}
		}

		rep1 (i, 24) {
			if (t1 - t2 >= i*3600 && t1 - t2 <= i*3600 + hr_limit) {
				return to_string(i) + " hours ago";
			}
		}
	}

};