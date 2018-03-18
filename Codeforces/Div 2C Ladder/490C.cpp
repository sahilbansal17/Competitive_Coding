/* 	Problem Link 	: 	http://codeforces.com/problemset/problem/490/C
	Problem Name 	: 	Hacking Cypher
 	author 			: 	sahilbansal17
	date			:	4th Feb, 2018/27th Feb, 2018	
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
#define rrep(i,n) rfl(i,n-1,0)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

string s;
int prefixModulo(char n, int m_10, int prev, int a){
	int next = n - 48; // ascii value of 0 is 48
	return (((prev * m_10)%a + next % a))%a ;
}
int suffixModulo(char n, int m_10, int prev, int b){
	int next = n - 48; // ascii value of 0 is 48
	return (((next % b) * m_10)%b + prev)%b ;
}

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int a,b,len;
	
	cin >> s;
	len = slen(s);
	cin >> a >> b;

	int ma10,prevPrefix = 0,mb10,prevSuffix = 0;
	ma10 = 10 % a;
	mb10 = 1 % b;

	int Parr[1000001];
	int Sarr[1000001];
	rep(i,len){
		prevPrefix = prefixModulo(s[i],ma10,prevPrefix,a);
		// cout << prevPrefix << " ";
		Parr[i] = prevPrefix;
		prevSuffix = suffixModulo(s[len-i-1],mb10,prevSuffix,b);
		mb10 = (mb10 * (10%b))%b ;// get next power of 10 mod b
		// cout << prevSuffix << "\n";
		Sarr[len-i-1] = prevSuffix; 
	}
	bool res = 0;
	int index;
	rep(i, len-1){ // len-1 since it must be divided into two parts, otherwise maybe just one part
		if(Parr[i] == 0){
			if(Sarr[i+1] == 0 && s[i+1]!='0'){
				res = 1;
				index = i;
			}
		}
	}
	if(res == 1){
		cout << "YES\n";
		rep(i, index+1){
			cout << s[i];
		}
		cout << "\n";
		fl(i, index + 1, len){
			cout << s[i];
		}
	}
	else{
		cout << "NO";
	}

	return 0;
}