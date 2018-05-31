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
#define MAX 2005

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, x;

    cin >> n;

    vi count(1001, 0);
    vi arr, res;
    rep(i, n){
        cin >> x;
        count[x] ++ ;
        arr.pb(x);
    }

   rep(i, arr.size()){
        int ele = arr[i];
        if(count[ele] == 1){
            res.pb(ele);
        }
        else if(count[ele] > 1){
            count[ele] --;
        }
    }

    cout << res.size() << "\n";
    rep(i, res.size()){
        cout << res[i] << " " ;
    }
	return 0;
}