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

	int n, m;
	ll x, y;

	vector < pair <ll, ll> > cf, tc;

	cin >> n;

	rep(i, n){
		cin >> x >> y;
		cf.pb(mp(x, y));
	}

	cin >> m;

	rep(i, m){
		cin >> x >> y;
		tc.pb(mp(x, y));
	}

	ll res = 0;

	srt(cf);
	srt(tc);

	int i = 0 , j = 0;

	while(i < n && j < m){
		if(cf[i].F == tc[j].F){
			res += max(cf[i].S, tc[j].S);
			i ++ ;
			j ++;
		}
		else{
			if(cf[i].F > tc[j].F){
				res += tc[j].S;
				j ++;
			}
			else{
				res += cf[i].S;
				i ++;
			}
		}
	}
	while(i < n){
		res += cf[i].S;
		i ++;
	}
	while(j < m){
		res += tc[j].S;
		j ++;
	}
	cout << res; 
	return 0;
}