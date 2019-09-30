#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 3e3+5;
ll dp[N][N];
string s,ss,ans;
ll solve(int i,int j);

int main(){
ll i,j,k,m;
memset(dp,-1,sizeof(dp));
cin >> s >> ss;
k = solve((int)s.size() - 1,(int)ss.size() - 1);
i = (int)s.size() - 1,j = (int)ss.size() - 1;
while(k){//k is number of char in LCS
    if(s[i] == ss[j]){
        ans += s[i];
        i -= 1,j -= 1;
        k--;
    }
    else if(i && dp[i-1][j] == k)
        i--;
    else j--;
}
reverse(ans.begin(), ans.end());
cout << ans << "\n";
    return 0;
}

ll solve(int i,int j){
    if(i < 0 || j < 0)return 0;
    else if(dp[i][j] != -1)return dp[i][j];
    else if(s[i] == ss[j])
        return dp[i][j] = 1 + solve(i-1,j-1);
    return dp[i][j] = max(solve(i-1,j),solve(i,j-1));
}