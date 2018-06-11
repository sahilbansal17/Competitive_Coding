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
	char ch;
	cin >> n;
	bool valid = true; 

	vector < char > s; 
	s.pb('0');
	rep(i, n){
		cin >> ch;
		s.pb(ch);
	}
	s.pb('0');
	// 0 at the start and the end as boundary conditions 
	rep(i, n){
		// if any three 0's occur together, condition 2 fails 
		if(s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0'){
			valid = false;
			break;
		}
	}
	rep(i, n + 1){
		// if any two 1's occur together, condition 1 fails 
		if(s[i] == '1' && s[i + 1] == '1'){
			valid = false;
			break;
		}
	}
	
	if(valid){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

	return 0;
}