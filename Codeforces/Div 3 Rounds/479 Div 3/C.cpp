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

	int n, k, val ;
	cin >> n >> k;

	vi a;

	rep(i, n){
		cin >> val;
		a.pb(val);
	}	

	srt(a);

	if(k == n){
		cout << a[n-1];
	}
	else if(k == 0){
		if(a[0] == 1){
			cout << "-1";
		}
		else{
			cout << "1";
		}
	}
	else if(a[k] == a[k-1]){
		cout << "-1";
	}
	else{
		cout << a[k-1];
	}


	return 0;
}