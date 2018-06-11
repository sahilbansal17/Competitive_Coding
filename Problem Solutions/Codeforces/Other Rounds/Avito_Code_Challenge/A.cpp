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

bool checkPali(string s){
	int len = slen(s);

	rep(i, len/2){
		if(s[i] != s[len - i - 1]){
			return 0;
		}
	}
	return 1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s ;

	cin >> s;

	// cout << checkPali(s);

	int max = 0;
	rep(i, slen(s)){
		fl(j, i, slen(s)){
			int length = slen(s) - j;
			if(!checkPali(s.substr(j, length))){
				if(length > max){
					max = length;
				}
			}
		}
	}
	cout << max;
	return 0;
}