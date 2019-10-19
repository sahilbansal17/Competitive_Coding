// CodeChef October Challenge 2019 - Array Modification
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod(ll x, ll y){
	return x-y*((ll)(x/y));
}
int main(){
	ll t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		std::vector<ll> v(n);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}		
		if(k>(3*n)){
			if(n&1){
				v[n/2] = 0;
			}
			k = k%(3*n);
		}
		for(int i=0;i<k;i++){
			ll val = i%n;
			v[val] = v[val] ^ v[n-1 - val];
		}
		for(ll i=0;i<n;i++){
			cout<<v[i]<<" ";
		}
		cout<<"\n";
	}
}
