#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1e5+5;

ll dp[102][N] = {-1},n,w,v[2][N];
ll solve(int index, ll weight);
ll minf = -0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    ll i,j,m,w;    
    cin >> n >> w;
    for(i = 1;i <= n;i++)
    cin >> v[0][i] >> v[1][i]; // weight,value
    cout << solve(n,w) << "\n";

    return 0;
}

ll solve(int index, ll weight){
    if(weight < 0)
        return minf;
    else if(index <= 0)
        return 0;

    if(dp[index][weight] != -1)
        return dp[index][weight];
    return dp[index][weight] = max(v[1][index]
        + solve(index - 1,weight - v[0][index]),solve(index - 1,weight));
}