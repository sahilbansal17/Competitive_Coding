/* 	author 	: 	sahilbansal17
	date	:	20th Jan, 2018	
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
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,max=-10000000,x,temp;
	cin >> n;

	

	rep(i,n){
		cin >> x;
		temp = sqrt(x);
		if(temp*temp != x){
			if(x > max){
				max = x;
			}
		}
	}

	cout << max;
	return 0;
}