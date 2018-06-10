#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rep1(i,n) fl(i,1,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 10010



int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n, a, b, ct = 0;

	cin >> n >> a >> b;

	if(a < b){
		swap(a, b);
	}

	string s; 

	cin >> s;

	if(s[0] == '.' && a > 0){
		ct += 1;
		a -= 1;
		s[0] = 'A';
	}
	rep1(i, n){
		if(s[i] == '.' && s[i - 1] == 'A' && b > 0){
			s[i] = 'B';
			ct += 1;
			b -= 1;
			continue;
		}
		if(s[i] == '.' && s[i - 1] == 'B' && a > 0){
			s[i] = 'A';
			ct += 1;
			a -= 1;
			continue;
		}
		if(s[i] == '.' && s[i - 1] == '.'){
			if(a > 0){
				s[i] = 'A';
				ct += 1;
				a -= 1;
			}
			else if(b > 0){
				s[i] = 'B';
				ct += 1;
				b -= 1;
			}
			continue;
		}
		if(s[i] == '.' && s[i - 1] == '*'){
			if(a > b && b >= 0){
				s[i] = 'A';
				ct += 1;
				a -= 1;
			}
			else if(b > a && a >= 0){
				s[i] = 'B';
				ct += 1;
				b -= 1;
			}
			else if(a == b && a > 0){
				s[i] = 'A';
				ct += 1;
				a -= 1;
			}
		}
	}
	cout << ct;
	return 0;
}