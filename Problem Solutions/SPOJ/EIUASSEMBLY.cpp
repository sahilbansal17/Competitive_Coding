
#include <bits/stdc++.h> 
using namespace std;

	
               long long n,m;
               vector<pair<long long>> vec;
	ll oper(ll mid){
		long long d=0;
		for(int i=0;i<n;i++){
			d+=max(0ll,mid-vec[i].ff)*vec[i].ss;
			if(d>=INF)
				return 0;
		}
		if(d<=m)
			return 1;
		return 0;
	}
                void solve(){   
 
                	vec.clear();
                	n=0,m=0;
                	cin>>n>>m;
                	for(int i=0;i<n;i++){
                		ll x,y;
                		cin>>x>>y;
                		vec.pb(mp(x,y));
                	}
 
                	long long lo=0,hi=INF;
                	while(lo<hi){
                		ll mid=(lo+hi+1)>>1;
                		if(oper(mid))
                			lo=mid;
                		else
                			hi=mid-1;
                	}
                	cout<<lo<<'\n';
                }
 
                int main(){ 
                        ll t;
                        t=1;
                        cin>>t;
                        for (int i=1; i<=t; i++){
               	         solve();
                         }
        return 0; 
}         
