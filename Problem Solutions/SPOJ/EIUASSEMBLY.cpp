/*
    AUTHOR:shivam51
    IIESTS
*/
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
 
#define add(x) accumulate(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
const int MOD = 1000000007;
const ll INF = 1e15;
const int MAX = 1e6;
//
//
	
               ll n,m;
               vpll vec;
	ll oper(ll mid){
		ll d=0;
		rep(i,0,n){
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
                	// vpll vec(n);
                	rep(i,0,n){
                		ll x,y;
                		cin>>x>>y;
                		vec.pb(mp(x,y));
                		// cin>>vec[i].ff>>vec[i].ss;
                	}
 
                	ll lo=0,hi=INF;
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
                        // hs;
                        ll t;
                        t=1;
                        cin>>t;
                        for (int i=1; i<=t; i++){
	                        // printf("Case #%d: ", i);
               	         solve();
                         }
        return 0; 
}         