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

	int n;

	cin >> n;

	vi a(n/2, 0);

	int odd = 1, even = 2, oddR = 0, evenR = 0;
	rep(i, n/2){
		cin >> a[i];
	}

	srt(a);

	rep(i, n/2){
		oddR += abs(a[i] - odd);
		evenR += abs(a[i] - even);
		odd += 2;
		even += 2;
	}
	cout << min(oddR, evenR);

	return 0;
}