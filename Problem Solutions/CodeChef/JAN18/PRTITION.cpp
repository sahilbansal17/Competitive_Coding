#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)

ll sum(int n){
	return 1LL*n*(n+1)/2;
}

vector <char> st(1000000);

void doItForMe(ll sum, int n, int x){
	if(n == x){
		doItForMe(sum, n-1, x);
		return;
	}
	if(sum == n){
		st[n-1] = '1';
		return;
	}
	if(sum < n){
		if(sum != x){
			st[sum - 1] = '1';
			return; 
		}
		else{
			// we can't take n+1
			st[n] = '0';
			doItForMe(sum+n+1, n, x);
			return;
		}
	}
	if(sum > n){
		st[n-1] = '1';
		doItForMe(sum - n , n-1 , x);
		return ;
	}

}
int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t,n,x,res;
	cin >> t;


	while(t--){

		cin >> x >> n;
		
		
		if(n % 4 == 3 || n % 4 == 0){ // case when sum from 1 to n is even
			if(x % 2 == 1){
				res = 0; // since odd number removed from even sum, not possible to partition
			}
			else{
				if(n == 3){
					res = 0;
				}
				else{
					res = 1;
				}
			}
		}
		else{ // case when sum from 1 to n is odd
			if(x % 2 == 0){
				res = 0; // since even number removed from odd sum, not possible to partition
			}
			else{
				if(n == 1 || n == 2){
					res = 0;
				}
				else{
					res = 1;
				}
			}
		}
		if(res == 0){
			cout << "impossible\n";
		}
		else{
			rep(i,n){
				st[i] = '0';
			}
			st[x-1] = '2';
			ll req_sum = (sum(n) - x)/2;
			doItForMe(req_sum, n, x);
			rep(i,n){
				cout << st[i];
			}
			cout << "\n";
		}
	}

	return 0;
}