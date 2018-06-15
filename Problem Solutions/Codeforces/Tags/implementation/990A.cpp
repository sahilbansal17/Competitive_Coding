#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll x1=(n%m)*b;
    ll x2=(((n/m)+1)*m-n)*a;
    ll ans=min(x1,x2);
    cout<<ans;
    return 0;
}
