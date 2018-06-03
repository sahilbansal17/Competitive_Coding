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
#define MAX 101
vi graph[MAX];
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, x, y;

    cin >> n;

    if(n == 1){
        cout << "YES";
        return 0;
    }
    
    rep(i, n - 1){
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    int count1 = 0, count2 = 0;
    fl(i, 1, n + 1){
        int adjacent = graph[i].size();
        if(adjacent == 1){
            count1 ++;
        }
        else if(adjacent == 2){
            count2 ++;
        }
    }
    if(count1 == 2 && count2 == n - 2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
	return 0;
}