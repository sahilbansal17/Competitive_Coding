#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define ll long long int
#define pii pair <int , int >
#define pb push_back
int x8[]= {1,1,1,0,0,-1,-1,-1};
int y8[]= {1,0,-1,1,-1,-1,0,-1};
int x4[]= {1,-1,0,0};
int y4[]= {0,0,1,-1};
ll mod=1e9+7;
ll inf=1e18;

void getac(){
  ll n;
  cin>>n;
  ll k;
  cin>>k;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j]>arr[i]){
        ans++;
      }
    }
  }
  ans=ans*k;
  for(int i=0;i<n;i++){
    ll x=0;
    for(int j=0;j<n;j++){
      if(arr[j]<arr[i]){
        x++;
      }
    }
    ans+=x*(((k)*(k-1))/2);
  }
  cout<<ans<<'\n';
}
int main()
{
  fastio;
  int t;
    

  t=1;
  cin>>t;

  while(t--)
  {
      getac();
  }

  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
  return 0;
}
