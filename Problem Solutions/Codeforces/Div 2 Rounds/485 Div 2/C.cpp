#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
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

#define MAX 3005
int s[MAX];
int c[MAX];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n;

    cin >> n;

    rep(i, n){
        cin >> s[i];
    }
    rep(i, n){
        cin >> c[i];
    }

    ll minCost = INT_MAX;

    fl(j, 1, n - 1){
        // fix j
        ll current = c[j];
        ll left = INT_MAX;
        ll right = INT_MAX;
        // find the best possible i whose cost is min and s[i] < s[j]
        rfl(i, j - 1, 0){
            if(s[i] < s[j] && c[i] < left){
                left = c[i];
            }
        }
        // find the best possible k whose cost is min and s[j] < s[k]
        fl(k, j + 1, n){
            if(s[k] > s[j] && c[k] < right){
                right = c[k];
            }
        }
        current += left + right;
        if(current < minCost){
            minCost = current;
        }
    }
    if(minCost == INT_MAX){
        cout << "-1";
    }
    else{
        cout << minCost;
    }
	return 0;
}