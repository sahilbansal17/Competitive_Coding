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
	#define MAX 100010


	
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, p;

	cin >> n >> p;

	string s;

	cin >> s;

	int blocks = n/p;

	rep(i, p){
		for(int j = i + p; j < n ; j += p){
			if(s[j] == '.' && s[i] != '.'){
				if(s[i] == '1'){
					s[j] = '0';
				}
				else{
					s[j] = '1';
				}
				// found 
				rep(k, n){
					if(s[k] == '.'){
						cout << "1";
					}
					else{
						cout << s[k];
					}
				}
				return 0;
			}
			else if(s[i] == '.' && s[j] != '.'){
				if(s[j] == '1'){
					s[i] = '0';
				}
				else{
					s[i] = '1';
				}
				// found
				rep(k, n){
					if(s[k] == '.'){
						cout << "1";
					}
					else{
						cout << s[k];
					}
				}
				return 0;
			}
			else if(s[i] == s[j] && s[i] == '.' && s[j] == '.'){
				// cout << "Here";
				s[i] = '1';
				s[j] = '0';
				// found
				rep(k, n){
					if(s[k] == '.'){
						cout << "1";
					}
					else{
						cout << s[k];
					}
				}
				return 0;
			}
			else if(s[i] != s[j]){
				// both are not '.' for sure
				rep(k, n){
					if(s[k] == '.'){
						cout << "1";
					}
					else{
						cout << s[k];
					}
				}
				return 0;	
			}
		}
	}		
	cout << "No";	

	return 0;
}