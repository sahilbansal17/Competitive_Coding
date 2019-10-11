/*****************************************************
@author: vichitr
Compiled On: 22nd Sept 2019
*****************************************************/
#include<bits/stdc++.h>
#define MAX 9223372036854775807
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define ip pair<int, int>

#define loop(i,n) for(int i=0;i<n;i++)
#define loops(i,s,n) for(int i=s;i<=n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const ll MOD = 1e9+7;
const ll SZ = 107;
const ll N = 1e5+7;
const ll M = 2e5+7;

ll pwr(ll x, ll y)
{
    ll r = 1LL;
    while(y)
    {
        if(y&1)
            r = (r * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

int inv(int x)
{
	return pwr(x, MOD-2ll);
}

int fact[N];
void cal()
{
    fact[0] =1;
    for(int i=1;i<N;i++)
    {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

void solve()
{
	int n, m, k; cin>>n>>m>>k;
    int ans = 0;
    for(int i=n;i>=k;i--)
    {
        int here = fact[n];
        here *= inv(fact[n-i]);
        here %= MOD;
        here *= inv(fact[i]);
        here %= MOD;
        here *= pwr(m-1, n-i);
        here %= MOD;
        ans += here;
        ans %= MOD;
    }
    cout<<ans<<endl;
}

signed main()
{
    fast;
    cal();
    int t=1;
    cin >>t;
    while(t--){
        solve();
        
    }
    return 0;
}

/*****************************
5 4
1 2
4 3
1 4
3 4
1
6 5
2 3
2 1
3 4
6 5
4 5
0
****************************/
