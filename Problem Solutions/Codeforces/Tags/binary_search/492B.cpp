#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, l, loc;

	cin >> n >> l;

	vi lantern;

	rep(i, n){
		cin >> loc;
		lantern.pb(loc);
	}
	
	srt(lantern);

	int maxGap = 0, currentGap;

	fl(i, 1, n){
		currentGap = lantern[i] - lantern[i - 1];
		if(currentGap > maxGap){
			maxGap = currentGap ;
		}
	}

	double res;
	// following two lines are extremely important otherwise answer comes up in exp form(double) and thus fails
	cout << fixed;
	cout << setprecision(10);
	res = max(1.0 * maxGap/2, max(1.0 * lantern[0], l - 1.0 * lantern[n - 1]));

	cout << res; 
	return 0;
}