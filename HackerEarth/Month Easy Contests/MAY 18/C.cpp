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

ll solve(vi a, int start, int end, ll sumWant, ll sum, int &min){
	if(sum < sumWant){
		return 0;
	}
	if(start > end){
		return 0;
	}
	if(sum == sumWant){
		int deleted = a.size() - (end - start) - 1;
		// cout << deleted << " ";
		if(deleted < min){
			min = deleted;
		}
		return 1 + solve(a, start + 1, end, sumWant, sum - a[start], min) + solve(a, start, end - 1, sumWant, sum - a[end], min);
	}
	else{
		return solve(a, start + 1, end, sumWant, sum - a[start], min) + solve(a, start, end - 1, sumWant, sum - a[end], min);
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, val;
	ll k, sum = 0;

	cin >> n >> k;

	vi a;

	rep(i, n){
		cin >> val;
		a.pb(val);
		sum += val;
	}

	int min = INT_MAX;
	ll count = solve(a, 0, n-1, k, sum, min);
	cout << count << " " << min;

	return 0;
}