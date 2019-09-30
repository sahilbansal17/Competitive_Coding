#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5+5;
ll dp[N] = {-1},v[N],k,n;
const int inf = 0x3f3f3f3f;
ll check(int index);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll i,j,m;
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for(i = 0;i < n;i++)
        cin >> v[i];
    cout << check(0) << "\n";

    return 0;
}

ll check(int index){
    // if out of bounds, return a very large number
    if(index >= n)
        return inf;
    // if result is already calculated, don't recalculate
    else if(dp[index] != -1)
        return dp[index];

    else if(index == n-1)
        return dp[index] = 0;
    ll var = inf;
    // calculate the result, store it and return
    for(int i = index + 1;i <= min(n-1,k+index);i++)
        var = min(var,abs(v[index]-v[i]) + check(i));
    return dp[index] = var;
}