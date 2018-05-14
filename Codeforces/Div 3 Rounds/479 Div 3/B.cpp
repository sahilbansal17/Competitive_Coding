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

	int n;
	string s;

	cin >> n ;
	cin >> s;

	vector < pair <string, int> > v;

	rep(i, n-1){
		string res;
		res += s[i];
		res += s[i+1];
		bool found = 0;
		rep(j, v.size()){
			if(v[j].F == res){
				found = 1;
				v[j].S ++;
			}
		}
		if(!found){
			v.pb(mp(res, 0));
		}
		// cout << res << "\n";
	}
	int maxIndex = 0, maxCount = 0;
	rep(i, v.size()){
		if(v[i].S >= maxCount){
			maxCount = v[i].S;
			maxIndex = i;
		}
	}
	cout << v[maxIndex].F;
	return 0;
}