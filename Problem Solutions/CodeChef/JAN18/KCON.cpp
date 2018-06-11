#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)

ll maxSubArrSum(ll a[], int n){
	ll msf = -1000010 ; // max_so_far
	ll meh = 0 ; // max_ending_here
	// s = 0;
	// e = 0;
	int loc = 0; 
	rep(i,n){
		meh += a[i];
		if(msf <= meh){
			msf = meh; 
			// s = loc;
			// e = i;
		}
		if(meh < 0){
			meh = 0;
			loc = i+1;
		}
	}
	return msf;

}

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,n,k;
	cin >> t;

	ll a[100010],b[300030];

	ll res,kadaneSum,t1,t2;
	while(t--){
		
		res = 0;

		cin >> n >> k;
		rep(i,n){
			cin >> a[i];
		}
		
		if(k == 1){
			res = maxSubArrSum(a,n);
		}
		else{
			rep(i,n){
				b[i] = a[i];
			}
			fl(i,n,2*n){
				b[i] = b[i-n];
			}
			fl(i,2*n,3*n){
				b[i] = b[i-n];
			}
			t1 = maxSubArrSum(b,2*n);
			t2 = maxSubArrSum(b,3*n);
			if(t2 > t1){
				res = t1 + (k - 2)*(t2 - t1);
			}
			else{
				res = t1;
			}
		}
		cout << res << "\n";
	}

	return 0;
}