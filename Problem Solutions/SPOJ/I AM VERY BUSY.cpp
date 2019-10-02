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
const ll INF = 1e18;
const int MAX = 100001;
//
//
                void solve(){   

                        ll n;
                        cin>>n;
                        vpll vec(n);
                        rep(i,0,n)
                                cin>>vec[i].ff>>vec[i].ss;
                        sort(all(vec));
                        ll wl=vec[n-1].ff;
                        ll cnt=1;
                        for(int i=n-2;i>=0;i--){
                                if(vec[i].ss>wl)
                                        continue;
                                ++cnt;
                                wl=vec[i].ff;
                        }
                        cout<<cnt<<'\n';
                }

                int main(){ 
                        // hs;
                        ll t;
                        // t=1;
                        cin>>t;
                        for (int i=1; i<=t; i++){
                                // printf("Case #%d: ", i);
                                solve();
                         }
        return 0; 
}         
