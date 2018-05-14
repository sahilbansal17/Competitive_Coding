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
	
	int n;

	cin >> n;

	vi a(n),count(100005,0);

	rep(i,n){
		cin >> a[i];
		count[a[i]] ++ ;
	}

	srt(a);

	int ind = n-2, ct = 1;
	while(a[ind] == a[n-1] && ind >= 0){
		ct ++ ;
		ind --;
	}

	if(ct % 2 == 1){
		cout << "Conan";
	}
	else{
		int flag = 1;
		rep(i,100001){
			if(count[i] % 2 == 1){
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			cout << "Agasa";
		else
			cout << "Conan";
	}
	return 0;
}