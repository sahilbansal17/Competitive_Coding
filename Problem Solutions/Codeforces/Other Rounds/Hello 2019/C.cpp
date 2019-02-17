#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector <string> vs;
typedef vector < vi > vvi;
typedef vector < vll > vvll;

#define fl(i, a, b)	for (int i(a); i <= (b); i ++)
#define rep(i, n)		fl (i, 1, (n))
#define loop(i, n)		fl (i, 0, (n) - 1)
#define rfl(i, a, b)	for (int i(a); i >= (b); i --)
#define rrep(i, n)		rfl (i, (n), 1)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define sz(x) ((int) (x).size())
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	FAST_IO;

	int n, len;
	cin >> n;

	string s;

	map <int, int> cnt;

	int open, closed, diff, res = 0;
	rep (i, n) {
		cin >> s;

		len = slen(s);

		open = 0, closed = 0;
		loop (j, len) {
			if (s[j] == '(') {
				open ++;
			}
			else if (open > 0) {
				open --;
			}
			else {
				closed ++;
			}
		}

		diff = closed - open;
		if (closed > 0 && open > 0) {
			continue;
		}
		
		if (cnt[-1*diff] > 0) {
			cnt[-1*diff] --;
			res ++;
		}
		else {
			cnt[diff] ++;
		}
	}

	cout << res << endl;
	return 0;
}