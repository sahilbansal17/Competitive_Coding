// CodeChef October Challenge 2019 - Array Modification
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		std::vector<ll> v(n);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}		
		// Pattern noticed is repetition of same sequence after 3*n numbers, can be reduced
		if(k>(3*n)){
			if(n&1){
				v[n/2] = 0; // always 0, self XOR
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
