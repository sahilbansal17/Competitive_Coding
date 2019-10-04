/******************************************
* AUTHOR : AAYUSH GARG*
* NICK : aayushgarg_03 *
* INSTITUTION : BIT MESRA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define dd double
#define ld long double
#define for0(i, n) for(ll i = 0; i < n; i++)
#define for2(a,b,c) for(ll i=a;i<b;i+=c)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define vec vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define VP vector< pii >
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define ascii(c) (int)char (c)
#define all(v) (v).begin(),(v).end()
#define Sort(v) sort(v.begin(), v.end(), sortbysec);
#define N 1000000



int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll t;
cin>>t;
while(t--)
{
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for0(i,n)
	 cin>>arr[i];

	 VP v;
 
    ll sum = 0;
    ll cnt = 0, maxcnt = 0; 
  
   
    for (ll i = 0; i < n; i++) { 
          
       
        if ((sum + arr[i]) <= k) { 
            sum += arr[i];  
            cnt++; 
        }  
  
         
        else if(sum!=0) 
        { 
            sum = sum - arr[i - cnt] + arr[i]; 
        } 
  
        
        maxcnt = max(cnt, maxcnt);
        v.pb(mp(sum,maxcnt));

    }   

    ll s = v.size();
    Sort(v);
    
    ll minn = N;
    for0(i,s)
    {
    	if(v[i].S == maxcnt)
    		minn = min(v[i].F,minn);
    }
    cout<<minn<<" "<<cnt<<endl;

     

}

return 0;
}
