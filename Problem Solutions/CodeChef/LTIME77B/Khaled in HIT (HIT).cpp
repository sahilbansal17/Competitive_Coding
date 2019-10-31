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
  int n;
  cin>>n;
  int arr[n];
  bool ans=true;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  unordered_map < int , int > m;
  for(int i=0;i<=n-1;i++){
    m[arr[i]]++;
  }
  for(int i=1;i<=100;i++){
    m[i]+=m[i-1];
  }
  int x=0;
  while(x<=100 && m[x]<=n/4){
    x++;
  }

  if(m[x-1]!=n/4){
    ans=false;
  }
  int y=x;
  while(y<=100 && m[y]-m[x-1]<=n/4){
    y++;
  }
  if(m[y-1]-m[x-1]!=n/4){
    ans=false;
  }
  int z=y;
  while(z<=100 && m[z]-m[y-1]<=n/4){
    z++;
  }
  if(m[z-1]-m[y-1]!=n/4){
    ans=false;
  }
  if(m[100]-m[z-1]!=n/4){
    ans=false;
  }
  if(ans){
    cout<<x<<' '<<y<<' '<<z<<'\n';
  }
  else{
    cout<<-1<<'\n';
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
