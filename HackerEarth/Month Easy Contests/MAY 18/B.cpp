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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, x, y;

	cin >> n;

	vi first, second;

	rep(i, n){
		cin >> x >> y;

		first.pb(x);
		second.pb(y);
	}

	srt(first);
	srt(second);

	// rep(i, n){
	// 	cout << first[i] << " " << second[i] << "\n";
	// }

	int maxHappy = 0, minCandy, index_sec = n - 1, cur_happy = 0;
	rfl(i, n-1, 0){
		int cur = first[i];
		// cout << index_sec << " ";
		if(index_sec == -1){
			break;
		}
		while(index_sec >= 0 && second[index_sec] >= cur){
			cur_happy ++;
			index_sec --;
		}
		if(cur_happy + (i - n + 1) >= maxHappy){
			maxHappy = cur_happy + (i - n + 1);
			minCandy = cur;
		}
	}
	cout << minCandy << " " << maxHappy;
	
	return 0;
}