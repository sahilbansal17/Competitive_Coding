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
#define MAX 2005

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	ll n, m, ai, bj ;
	cin >> n >> m;

	vector <ll> rooms, queries, dormitory;
	ll current = 0;
	rep(i, n){
		cin >> ai;
		rooms.pb(ai);
		dormitory.pb(current + ai);
		current += rooms[i];
		// cout << roomNo[i] << " ";
	}
	ll k = 0, room;
	rep(i, m){
		cin >> bj;
		queries.pb(bj);
		while(bj > dormitory[k]){
			k ++;
		}
		if(k > 0)
			room = bj - dormitory[k - 1];
		else 
			room = bj;
		cout << k + 1 << " " << room;
		cout << "\n";
	}

	return 0;
}