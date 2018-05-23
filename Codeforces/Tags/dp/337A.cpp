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

	int n, m, fi;
	vi f;

	cin >> n >> m ;
	rep(i, m){
		cin >> fi;
		f.pb(fi);
	}

	// solve 
	srt(f);

	// rep(i, m){
	// 	cout << f[i] << " ";
	// }
	// cout << "\n";

	int currentDiff, minDiff = 1001;
	rep(i, m - n + 1){
		currentDiff = f[i + n - 1] - f[i];
		// cout << currentDiff << " ";
		if(currentDiff < minDiff){
			minDiff = currentDiff;
		}
	}
	// cout << "\n";	
	cout << minDiff;
	return 0;
}