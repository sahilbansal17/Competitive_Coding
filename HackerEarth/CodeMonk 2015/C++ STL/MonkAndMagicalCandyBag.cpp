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
	
	int T, N, K;

	cin >> T;

	ll eaten, currentCandies, candies;
	rep(i, T){
		eaten = 0;
		cin >> N >> K;

		priority_queue <ll> bags;

		rep(j, N){
			cin >> candies;
			bags.push(candies);
		}

		rep(j, K){
			currentCandies = bags.top();
			eaten += currentCandies;
			bags.pop();
			bags.push(currentCandies / 2);
		}

		cout << eaten << "\n";

		while(!bags.empty()){
			bags.pop();
		}
	}
	return 0;
}