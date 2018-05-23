// after the contest

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

	int n, k, l, len;

	cin >> n >> k >> l;

	vi staves;

	rep(i, n*k){
		cin >> len;
		staves.pb(len);
	}

	srt(staves);

	// rep(i, n*k){
	// 	cout << staves[i] << " ";
	// }

	int boundary = 1, min = staves[0];
	// boundary denotes the index after which a min stave can't be chosen
	fl(i, 1, n*k){
		if(staves[i] - min > l){
			break;
		}
		boundary ++;
	}
	// cout << boundary ;

	if(boundary < n){
		cout << "0"; // can't create n barrels 
	}
	else{
		// for each i from 1 to n, take no more than k smallest staves from this segment in the i-th barrel, 
		// but in such way, that there are at least n - i staves left for next barrels.
		int u = 0, i;
		ll res = 0; // final sum of volumes
		while(i < n){
			res += staves[u]; 
			int remaining = n - i - 1 ;
			int j = 0;
			while(j < k){
				if(u < boundary - remaining){
					u ++;
				}
				else{
					break;
				}
				j ++;
			}
			i ++ ;
		}
		cout << res;
	}

	return 0;
}