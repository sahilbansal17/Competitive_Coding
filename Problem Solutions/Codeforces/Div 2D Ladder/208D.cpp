/* 	Problem Link	: 	http://codeforces.com/problemset/problem/208/D
	Problem Name	:	Prizes, Prizes, more Prizes
 	author		: 	sahilbansal17
	date		:	4th Feb, 2018
*/
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

	int n,x;
	ll amt = 0;
	cin >> n;
	vector <pii> a;
	vi p(n);
	vector <ll> count(6,0);
	rep(i,n){
		cin >> p[i];
	}
	rep(i,5){
		cin >> x;
		a.pb(mp(x,i+1));
	}
	srt(a);
	// rep(i,5){
	// 	cout << a[i].F << " " << a[i].S << "\n";
	// }
	rep(i,n){
		amt += p[i];
		rfl(j,4,0){
			if(a[j].F <= amt){
				count[a[j].S] += amt/a[j].F;
				amt -= a[j].F * (amt/a[j].F); 
			}
		}
	}
	fl(i,1,6){
		cout << count[i] << " ";
	}
	cout << "\n" << amt;
	return 0;
}
