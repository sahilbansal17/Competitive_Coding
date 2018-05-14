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
#define F first
#define S second

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,pos,l,r,res = 0;

	cin >> n >> pos >> l >> r;

	if(pos <= l){
		res = (l-pos) + (r - l) + 2;
		if(l == 1){
			res -= 1;
		}
		if(r == n){
			res -= (r - l) + 1;
		}
	}
	else if(pos >= r){
		res = (pos - r) + (r - l) + 2;
		if(l == 1){
			res -= (r - l) + 1;
		}
		if(r == n){
			res -= 1;
		}
	}
	else{
		if(l == 1){
			res += (r - pos) + 1;
		}
		if(r == n){
			res += (pos - l) + 1;
		}
		if(l == 1 && r == n){
			res = 0;
		}
		if(l != 1 && r != n){
			int res1 = (pos - l) + 1 + 1 + (r - l);
			int res2 = (r - pos) + 1 + 1 + (r - l);
			res = min(res1, res2);
		}
	}
	cout << res ;
	return 0;
}