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

	int t;
	cin >> t;

	int n;
	while (t --) {
		cin >> n;

		vector <ll> from1(n + 1, 0), fromn(n + 1, 0);
		rep (i, n) {
			cin >> from1[i];
		}
		rep (i, n) {
			cin >> fromn[i];
		}

		if (from1[1] != 0 || fromn[n] != 0) {
			cout << "No" << endl;
			continue;
		}

		ll sum = from1[1] + fromn[1];
		rep (i, n) {
			if (from1[i] + fromn[i] < sum) {
				sum = from1[i] + fromn[i];
			}
		}

		for (int i = 2; i < n; i ++) {
			if (from1[i] == 0 || fromn[i] == 0) {
				cout << "No" << endl;
				goto done;
			}
		}

		rep (i, n) {
			if (sum + fromn[i] < from1[i]) {
				// trace1(i);
				cout << "No" << endl;
				goto done;
			}
			if (sum + from1[i] < fromn[i]) {
				// trace1(i);
				cout << "No" << endl;
				goto done;
			}
		}

		cout << "Yes" << endl;
		continue;
		done:
		continue;
	}

	return 0;
}