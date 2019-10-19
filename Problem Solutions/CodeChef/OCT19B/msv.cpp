// CodeChef - October Challenge 2019 - Chef and Maximum Star Value
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll t,n,count;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		ll ans = 0;
		ll MAX = *max_element(arr, arr + n); 
		ll cnt[MAX + 1] = {0};
		for(ll i=0;i<n;i++){
			ll count = 0;
			ll val = arr[i];
			if(cnt[val] != 0){
				count= cnt[val];
			}
			ll j=1;
			while(j<= sqrt(val)){
				if(val%j==0){
                	cnt[j]++;
					if(j!=(val/j)){
                    	cnt[val/j]++;
                    }
                }
                j++;
			}
			ans = (ans > count) ? ans:count;
		}
		cout<<ans<<"\n";
	}
}
