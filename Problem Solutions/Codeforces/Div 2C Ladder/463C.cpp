/*  
    problem_link : http://codeforces.com/problemset/problem/463/C
    author      :   sahilbansal17
    date        :   16th March, 2018  
    Reference taken from satyaki3794's submission: 
    http://codeforces.com/contest/463/submission/7780836  
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

ll l_diag[4001], r_diag[4001];
int arr[2001][2001];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    rep(i, n){
       rep(j, n){
            scanf("%d", &arr[i][j]);
            l_diag[i-j+n] += arr[i][j]; // '\' type digaonal
            r_diag[i+j] += arr[i][j]; // '/' type diagonal 
        }
    }

    pii odd,even;
    ll oddmax = -1, evenmax = -1;
    rep(i, n){
        rep(j, n){
            ll sum = l_diag[i-j+n] + r_diag[i+j] - arr[i][j];
            // since arr[i][j] is included twice
            if((i+j)%2 == 0 && sum > evenmax){
                evenmax = sum;
                even = pii(i,j);
            }
            else if((i+j)%2 == 1 && sum > oddmax){
                oddmax = sum;
                odd = pii(i,j);
            }
        }
    }
    printf("%lld\n", oddmax + evenmax);
    printf("%d %d %d %d", odd.first+1, odd.second+1, even.first+1, even.second+1);
    return 0;
}
