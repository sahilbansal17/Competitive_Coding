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

#define eps 10e-6
/*
	My original submission in the contest failed on main cases
	because I used epsilon to be 10e-9 in that. 
	Accepted: http://codeforces.com/contest/987/submission/38774991
	Failed: http://codeforces.com/contest/987/submission/38735081

	This happened due to some compiler optimizations made by gcc:
	http://codeforces.com/blog/entry/59720?#comment-434361
*/
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int x, y;

	cin >> x >> y;

	double lgXPowY = y * log(x);	
	double lgYPowX = x * log(y);	
	
	if(abs(lgXPowY - lgYPowX) < eps){
		cout << "=";
	}
	else if(lgXPowY < lgYPowX){
		cout << "<";
	}
	else{
		cout << ">";
	}
	return 0;
}