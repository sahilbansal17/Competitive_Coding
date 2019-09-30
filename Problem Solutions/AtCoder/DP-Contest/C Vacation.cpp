#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5+5;
const int inf = 0x3f3f3f3f;
ll dp[3][N] = {inf},v[3][N],k,n;

ll check(int index);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
ll i,j,m;
memset(dp,-1,sizeof(dp));

    cin >> n;
    for(i = 0;i < n;i++)
        cin >> v[0][i] >> v[1][i] >> v[2][i];
    for(auto it:{0,1,2})
        dp[it][0] = v[it][0];
    for(i = 1;i < n;i++){
        for(auto it:{0,1,2}){
            for(auto iit:{0,1,2}){
                if(it != iit)
                    dp[it][i] = max(dp[it][i],v[it][i] + dp[iit][i-1]);
            }
        }
    }
    cout << max({dp[0][n-1],dp[1][n-1],dp[2][n-1]}) << "\n";
    return 0;
}
