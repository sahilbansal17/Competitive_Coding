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

	int n, w;

	cin >> n >> w;

	ll pass, sum = 0, maxi = INT_MIN, mini = 0;
	rep(i, n){
		cin >> pass;
		sum += pass;
		if(sum > maxi){
			maxi = sum;
		}
		if(sum < mini){
			mini = sum;
		}
	}	
	if(maxi > w){
		cout << "0";
	}
	else if(mini < -w){
		cout << "0";
	}
	else{
		// cout << maxi << " " << mini << "\n";
		maxi -= mini; // if mini was negative, that amount ADDED to maxi as minimum initial passengers 
		if(maxi > w){
			cout << "0";
		}
		else if(maxi < abs(mini)){
			cout << w - abs(mini) + 1;
		}
		else{
			cout << w - maxi + 1;
		}
	}
	return 0;
}