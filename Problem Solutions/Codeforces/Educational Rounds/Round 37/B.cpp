/*
	author	:	sahilbansal17
	date		:	2nd Feb, 2018
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
#define F first
#define S second
#define slen(s) s.length()

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin >> t;

	while(t--){
		int n,l,r;
		cin >> n;

		int ct = 0;
		rep(i,n){
			cin >> l >> r;
			if(l > ct){
				ct = l;
			}
			if(r >= ct){
				cout << ct << " ";
				ct ++;
			}
			else{
				cout << 0 << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
