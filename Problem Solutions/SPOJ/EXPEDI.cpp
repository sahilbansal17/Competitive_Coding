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
                        ll dist,fl;
                        cin>>dist>>fl;
                        rep(i,0,n)
                                vec[i].ff=dist-vec[i].ff;
                        vec.pb(mp(dist,0));
                        sort(all(vec));
                        priority_queue<ll> q;

                        ll cnt=0;
                        rep(i,0,n+1){
                                while(!q.empty()&&fl<vec[i].ff){
                                        fl+=q.top();
                                        q.pop();
                                        ++cnt;
                                        // cout<<q.top()<<" ";
                                }
                                if(fl<vec[i].ff){
                                        cout<<"-1\n";
                                        return ;
                                }
                                q.push(vec[i].ss);
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
