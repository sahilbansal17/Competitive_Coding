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
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, k, rat, org;

	cin >> n >> k;
	org = k;
	vi ht(101, 0);

	int index[101];
	rep(i, n){
		cin >> rat;
		ht[rat] ++ ;
		index[rat] = i + 1;
	}

	vi res;

	fl(i, 1, 101){
		if(ht[i] > 0){
			res.pb(index[i]);
			k --;
		}
	}
	if(k > 0){
		cout << "NO";
	}
	else{
		cout << "YES\n";
		rep(i, org){
			cout << res[i] << " ";
		}
	}
	return 0;
}