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

	int a, b, cb;

	cin >> a >> b;

	cb = b;
	vi A, B;

	while(a){
		int rem = a % 10;
		a = a/10;
		A.pb(rem);		
	}
	
	while(b){
		int rem = b % 10;
		b = b/10;
		B.pb(rem);
	}

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	// rep(i, A.size()){
	// 	cout << A[i];
	// }
	// cout << "\n";
	// rep(i, B.size()){
	// 	cout << B[i];
	// }

	if(A.size() > B.size()){
		cout << "-1";
	}
	else{
		if(A.size() < B.size()){
			srt(A);
			rfl(i, A.size() - 1, 0){
				cout << A[i];
			}
		}
		else{
			// equal size
			srt(A);
			reverse(A.begin(), A.end());
			int num = 0;
			rep(i, A.size()){
				num = num * 10 + A[i];
			}
			while(prev_permutation(A.begin(), A.end()) && num > cb){
				if(A[0] == 0){
					break;
				}
				num = 0;
				rep(i, A.size()){
					num = num * 10 + A[i];
				}
			}
			if(num > cb){
				cout << "-1";
			}
			else{
				cout << num;
			}
		}
	}
	return 0;
}