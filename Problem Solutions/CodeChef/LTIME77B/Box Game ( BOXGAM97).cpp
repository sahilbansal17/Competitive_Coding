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
  int n,k,p;
  cin>>n>>k>>p;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  if(p==0){
    if(k%2!=0){
      int ans=0;
      for(int i=0;i<n;i++){
        ans=max(ans,a[i]);
      }
    cout<<ans<<'\n';
    }
  else{
  
  
    int ans=0;
    for(int i=0;i<n;i++){
      if(i==0){
        ans=a[1];
      }
      else if(i==n-1){
        ans=max(ans,a[n-2]);
      }
      else{
        ans=max(ans,min(a[i+1],a[i-1]));
      }
    }
    cout<<ans<<'\n';
  }
  }
  else{
    if(k%2!=0){
      int ans=INT_MAX;
      for(int i=0;i<n;i++){
        ans=min(ans,a[i]);
      }
      cout<<ans<<'\n';
    }
    else{
    
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
      if(i==0){
        ans=a[1];
      }
      else if(i==n-1){
        ans=min(ans,a[n-2]);
      }
      else{
        ans=min(ans,max(a[i+1],a[i-1]));
      }
    }
    cout<<ans<<'\n';
    }
  }
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
