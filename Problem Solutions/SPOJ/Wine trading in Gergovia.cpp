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
	
                void solve(){   
                	ll n;
                	cin>>n;
                	if(n==0)
                		exit(0);
                	vll vec(n);
                	rep(i,0,n)
                		cin>>vec[i];
                	ll cnt=vec[0],ans=0;
                	rep(i,1,n){
                		ans+=abs(cnt);
                		cnt+=vec[i];
                	}
                	cout<<ans<<'\n';
                }

                int main(){ 
                        // hs;
                        ll t;
                        t=1;
                        // cin>>t;
                        for (int i=1; i<=t; i++){
	                        // printf("Case #%d: ", i);
                        	++t;
               	         solve();
                         }
        return 0; 
}         
