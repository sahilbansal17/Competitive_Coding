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

ll prime[N];

ll mulmod(ll a, ll b, ll m) 
{ 
    ll res = 0;  
    a = a % m; 
    while (b > 0) 
    { 
       
        if (b % 2 == 1) 
            res = (res + a) % m; 
  
        
        a = (a * 2) % m; 
  
        
        b /= 2; 
    } 
  
    return res % m; 
} 

ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        
        ll q = a / m; 
        ll t = m; 
  
        m = a % m, a = t; 
        t = y; 
  
        
        y = x - q * y; 
        x = t; 
    } 
  
    
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;     
  
    x = x % p;  
  
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % p; 
  
         
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}

void sieve() {
    for(ll i = 0;i < N;i++)
        prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for(ll i = 2;i*i < N;i++) {
        if(prime[i] == 0)
            continue;
        for(ll j = i*i;j < N;j+=i) {
            prime[j] = 0;
        }
    }
    for(ll i = 1;i < N;i++)
        prime[i] += prime[i-1];
}

ll binarySearch(ll arr[], ll l, ll r, ll x) 
{ 
    if (r >= l) { 
        ll mid = l + (r - l) / 2; 
  
         
        if (arr[mid] == x) 
            return mid; 
  
         
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    
    return -1; 
} 

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 

ll findMaxSubarraySum(ll arr[], ll n, ll sum)  
{  
     
    ll curr_sum = arr[0], max_sum = 0, start = 0;  
  
    
    for (ll i = 1; i < n; i++) {  
  
         
        if (curr_sum <= sum)  
           max_sum = max(max_sum, curr_sum);  
  
        
        while (curr_sum + arr[i] > sum && start < i) {  
            curr_sum -= arr[start];  
            start++;  
        }  
          
         
        curr_sum += arr[i];  
    }  
  
     
    if (curr_sum <= sum)  
        max_sum = max(max_sum, curr_sum);  
  
    return max_sum;  
}  
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll n,m;
cin>>n>>m;

ll a[n];

for0(i,n)
 cin>>a[i];

cout<<findMaxSubarraySum(a,n,m);



return 0;
}
