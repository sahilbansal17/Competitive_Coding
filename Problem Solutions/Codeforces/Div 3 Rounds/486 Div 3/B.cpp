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

bool cmpByLength(string s, string s2){
	if(s.length() == s2.length())
		return s < s2;
	return s.length() < s2.length();
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;

	cin >> n;

	bool res = true;

	vector <string> vs;
	string s, prev, next;
	rep(i, n){
		cin >> s;
		vs.pb(s);
	}
	sort(vs.begin(), vs.end(), cmpByLength);
	prev = vs[0];
	rep(i, n - 1){
		next = vs[i + 1];
		// cout << prev << " " << next << "\n";
		if(next.find(prev) == string::npos){
			res = false;
		}
		prev = next;
	}

	if(res){
		cout << "YES\n";
		rep(i, n){
			cout << vs[i] << "\n";
		}
	}
	else{
		cout << "NO";
	}
	return 0;
}