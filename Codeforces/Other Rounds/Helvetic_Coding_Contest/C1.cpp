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

	int N, p, x;

	cin >> N >> p;

	vi X;
	ll sum = 0;
	int maxSum = 0, part1 = 0, part2 = 0;
	rep(i, N){
		cin >> x;
		X.pb(x);
		sum += x;
	}

	rep(i, N){
		part1 = (part1 + X[i])%p;
		part2 = (sum - X[i])%p;
		sum -= X[i];
		if(part1 + part2 >= maxSum){
			maxSum = part1 + part2;
		}
	}

	cout << maxSum;

	return 0;
}