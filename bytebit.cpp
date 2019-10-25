
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
typedef vector<pi>vi;

#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(),v.end()
#define endl "\n"

const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;
const ll MINF=-INF;
const double EPS=1e-9;


int main(){
    fast;
    ll tc;
    cin >> tc;
    while(tc--){
      
       ll n;
       cin >> n;
       ll rem=n%26;
       ll k=n/26;
    //   cout << rem << " " << k << "\n";
       ll bits=0;
       ll nibbles=0;
       ll bytes=0;
       if(rem>0&&rem<=2)
          bits=pow(2,k);
        else if(rem>2&&rem<=10)
        nibbles=pow(2,k);
       else{
           if(rem==0)
           k=k-1;
       bytes=pow(2,k);
       }
       
       cout << bits << " " << nibbles << " " << bytes << "\n";
       
        
    }
    
    
    
    
}

